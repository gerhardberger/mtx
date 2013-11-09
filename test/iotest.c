#include <stdio.h>
#include "../mtx.h"

int main () {
  Matrix A = read("out.mtx");

  Index i, j;
  for (i = 0; i < A.n; ++i) {
    for (j = 0; j < A.m; ++j) printf("%0.f ", A.vals[i][j]);
    printf("\n");
  }


  int writed = write(A, "out.mtx");

  if (writed) printf("Print successful!\n");
  else printf("Print unsuccessful!\n");
  
  return 0;
}