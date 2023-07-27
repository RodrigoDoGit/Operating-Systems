#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
  if(strstr(argv[2], argv[1]) != NULL)
    printf("A primeira string ocorre na segunda!\n");

  else
    printf("A primeira string não ocorre na segunda!\n");

  return 0;
}
