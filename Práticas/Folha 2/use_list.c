#include <stdio.h>
#include "list.h"

int main(){
  list* l1 = list_new();

  list_add_first(1, l1);
  list_add_last(20, l1);

  list_print(l1);

  int x1 = list_get_first(l1);
  int x2 = list_get_last(l1);
  int x3 = list_size(l1);

  printf("%d\n", x1);
  printf("%d\n", x2);
  printf("%d\n", x3);

  list_remove_first(l1);
  list_remove_last(l1);

  int x4 = list_size(l1);

  printf("%d\n", x4);

  list_print(l1);
  
  return 0;
}
