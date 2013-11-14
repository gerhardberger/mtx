#include <stdio.h>
#include "../mtx.h"

int main () {
  mtx_print(add(read("./a.mtx"), read("./b.mtx")));
  
  return 0;
}