#include <stdio.h>
#include "../mtx.h"

int main () {
  Matrix a = read("./a.mtx");
  Matrix b = read("./b.mtx");
  Matrix c = read("./c.mtx");
  Matrix d = read("./d.mtx");
  Matrix e = read("./e.mtx");
  Matrix f = read("./f.mtx");
  Matrix g = read("./g.mtx");
  Matrix h = read("./e.mtx");
  Matrix i = read("./i.mtx");

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


  printf("\nExchange\n");
  exchange(&mult, 0, 1);
  mtx_print(&mult);


  printf("\nRow\n");
  Row r = row(&mult, 1);
  row_print(&r);


  printf("\nRow scale\n");
  scale_row(&r, -5);
  row_print(&r);


  printf("\nAdd row\n");
  add_row(&r, 0, &mult);
  mtx_print(&mult);


  printf("\nrref\n");
  rref(&e);
  mtx_print(&e);

  //printf("\n");

  //rref(&f);
  //mtx_print(&f);

  printf("\n");

  rref(&g);
  mtx_print(&g);


  printf("\nrank\n");
  printf("rank of e: %d\n", rank(&e));
  printf("rank of f: %d\n", rank(&f));
  printf("rank of g: %d\n", rank(&g));


  printf("\ntranspose\n");
  Matrix tr = transpose(&mult);
  mtx_print(&tr);


  printf("\ndet\n");
  printf("Determinant of h: %.2f\n", det(&h));
  printf("Determinant of i: %.2f\n", det(&i));

  return 0;
}