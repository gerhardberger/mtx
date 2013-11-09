#include <stdio.h>
#include "../mtx.h"

int main () {
  Matrix m = create(100, 32);



  Matrix A = identity(5);

  Index i, j;
  for (i = 0; i < A.n; ++i) {
    for (j = 0; j < A.m; ++j) printf("%0.f ", A.vals[i][j]);
    printf("\n");
  }

  return 0;
}