#include <stdio.h>
#include "../mtx.h"

int main () {
  Matrix a = read("./a.mtx");
  Matrix b = read("./b.mtx");
  Matrix c = read("./c.mtx");
  Matrix d = read("./d.mtx");

  printf("\nAdd\n");
  Matrix sum = add(&a, &b);
  mtx_print(&sum);
  

  printf("\nScale\n");
  Value l = 2;
  scale(&a, l);
  mtx_print(&a);


  printf("\nMultiply\n");
  Matrix mult = multiply(&c, &d);
  mtx_print(&mult);

  return 0;
}