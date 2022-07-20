#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  FILE* file1 = fopen(argv[1], "r");
  FILE* file2 = fopen(argv[2], "w");
  char c;
  
  if(file1 == NULL){
    printf("Ficheiro inexistente\n");
    return EXIT_FAILURE;
  }

  while((c=fgetc(file1)) != EOF)
    fputc(c, file2);

  fclose(file1);
  fclose(file2);
  
  return EXIT_SUCCESS;
}
