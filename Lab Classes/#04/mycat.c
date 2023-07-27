#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]){
  if(argc == 2){
    /* check if file can be opened and is readable */
    int fd = open(argv[1], O_RDONLY);

    if(fd == -1){
      printf("error: cannot open %s\n", argv[1]);
      return EXIT_FAILURE;
    }

    /* read contents in blocks and print to terminal */
    int nbytes;
    char buffer[BUFFER_SIZE];

    while((nbytes = read(fd, buffer, BUFFER_SIZE)) != 0)
      write(STDOUT_FILENO, buffer, nbytes);

    /* close file */
    close(fd);
  }

  if(argc > 2){
    int nbytes1;
    char buffer1[BUFFER_SIZE];
    
    for(int i=1; i<argc; i++){
      int fd1 = open(argv[i], O_RDONLY);

      if(fd1 == -1){
	printf("error: cannot open %s\n", argv[i]);
	return EXIT_FAILURE;
      }

      while((nbytes1 = read(fd1, buffer1, BUFFER_SIZE)) != 0)
	write(STDOUT_FILENO, buffer1, nbytes1);

      close(fd1);
    }
  }

  /* return cleanly */
  return EXIT_SUCCESS;
}
