#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  char *option, *filename;

  if(argc == 2){
    filename = argv[1];
  }

  if(argc == 3){
    option = argv[1];
    filename = argv[2];
  }
  
  FILE* file = fopen(filename, "r");
  
  if(file == NULL){
    printf("%s: Ficheiro inexistente\n", filename);
    exit(EXIT_FAILURE);
  }
  
  char c;
  
  while((c = fgetc(file)) != EOF){
    if(argc == 3 && strcmp(option, "-u") == 0)
      printf("%c", toupper(c));
    else if(argc == 3 && strcmp(option, "-l") == 0)  
      printf("%c", tolower(c));
    else
      printf("%c", c);
  }

  fclose(file);
  
  return EXIT_SUCCESS;
}
