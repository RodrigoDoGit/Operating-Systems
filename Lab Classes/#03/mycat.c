#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  char chr;
  FILE* file = fopen(argv[1], "r"); 

  if(file == NULL){
    printf("mycat: %s: Ficheiro inexistente\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if(argc == 2){
    while((chr = fgetc(file)) != EOF)
      printf("%c", chr);
  }
   
  if(argc > 2){
    for(int i=1; i<argc; i++){
      FILE *file1 = fopen(argv[i], "r");

      while((chr=fgetc(file1)) != EOF)
	printf("%c", chr);
      
      fclose(file1);
    }
  }
  
  fclose(file);
  exit(EXIT_SUCCESS);
}
