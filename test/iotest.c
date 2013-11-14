#include <stdio.h>
#include "../mtx.h"

int main () {
  Matrix A = read("a.mtx");

  mtx_print(A);


  int writed = write(A, "out.mtx");

  if (writed) printf("Print successful!\n");
  else printf("Print unsuccessful!\n");
  
  return 0;
}