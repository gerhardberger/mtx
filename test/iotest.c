#include <stdio.h>
#include "../mtx.h"

int main () {
  Matrix A = read("a.mtx");

  Index i, j;
  for (i = 0; i < A.n; ++i) {
    for (j = 0; j < A.m; ++j) printf("%0.f ", A.vals[i][j]);
    printf("\n");
  }
  
  return 0;
}