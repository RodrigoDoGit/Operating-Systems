#include <stdio.h>
#include "matrix.h"

int main(){
  matrix* z1 = matrix_new(12, 10);
  matrix* z2 = matrix_new(10, 8);

  matrix_print(z1);
  matrix_print(z2);

  double x1 = matrix_get(1, 2, z1);
  double x2 = matrix_get(3, 7, z2);

  printf("%f\n", x1);
  printf("%f\n", x2);

  matrix_set(1, 2, 3, z1);
  matrix_set(3, 7, 4, z2);

  matrix* z3 = matrix_add(z1, z2);
  matrix* z4 = matrix_sub(z1, z2);
  matrix* z5 = matrix_mul(z1, z2);
  matrix* z6 = matrix_trans(z1);
  matrix* z7 = matrix_trans(z2);

  printf("%d %d\n", z3->n, z3->m);
  printf("%d %d\n", z4->n, z4->m);
  printf("%d %d\n", z5->n, z5->m);
  printf("%d %d\n", z6->n, z6->m);
  printf("%d %d\n", z7->n, z7->m);

  return 0;
}
