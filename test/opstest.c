#include <stdio.h>
#include "../mtx.h"

int main () {
  Matrix a = add(read("./a.mtx"), read("./b.mtx"));

  mtx_print(a);
  
  return 0;
}