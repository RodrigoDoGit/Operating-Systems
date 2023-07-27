#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
  struct stat info;

  if(argc == 2){
    if(lstat(argv[1], &info) == -1){
      fprintf(stderr, "fsize: Can’t stat %s\n", argv[1]);
      return EXIT_FAILURE;
    }

    printf("%s size: %d bytes, disk_blocks: %d, owner id: %d, last modification: %s",
	   argv[1], (int)info.st_size, (int)info.st_blocks, (int)info.st_uid, ctime(&(info.st_mtim.tv_sec)));
    
    return EXIT_SUCCESS;
  }

  if(argc > 2){
    for(int i=1; i<argc; i++){
      struct stat info1;
      
      if(lstat(argv[i], &info1) == -1){
	fprintf(stderr, "fsize: Can't stat %s\n", argv[i]);
	return EXIT_FAILURE;
      }

      printf("%s size: %d bytes, disk_blocks: %d, owner id: %d, last modification: %s\n",
	     argv[i], (int)info1.st_size, (int)info1.st_blocks, (int)info1.st_uid, ctime(&(info1.st_mtim.tv_sec)));
    }

    return EXIT_SUCCESS;
  }
}
