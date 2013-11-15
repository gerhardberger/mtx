#include <stdio.h>
#include "../mtx.h"

int main () {
  Matrix m = create(100, 32);

  destroy(&m);

  printf("\nIdentity\n");
  Matrix A = identity(5);
  mtx_print(&A);

  printf("\nDuplicate\n");
  Matrix dupd = dup(&A);
  mtx_print(&dupd);

  return 0;
}