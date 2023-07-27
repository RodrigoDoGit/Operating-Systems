#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* toLower(char* str){
  for(int i=0; i<strlen(str)+1; i++){
    str[i] = tolower(str[i]);
  }
  
  return str;
}

int main(int argc, char* argv[]){
  printf("%s\n", toLower(argv[1]));

  return EXIT_SUCCESS;
}
