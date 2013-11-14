#include <stdio.h>
#include "../mtx.h"

int main () {
  Matrix m = create(100, 32);

  destroy(m);

  Matrix A = identity(5);

  mtx_print(A);

  return 0;
}