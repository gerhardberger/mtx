/*

  ops.c
  Created by Hegyi Gellért on 10/08/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/


/*
  Add
*/
Matrix add(Matrix a, Matrix b) {
  // Throw error if sizes are not equal
  assert(a.n == b.n && a.m == b.m);

  Matrix sum = create(a.n, a.m);
  Index i, j;
  for (i = 0; i < sum.n; ++i)
    for (j = 0; j < sum.m; ++j)
      sum.vals[i][j] = a.vals[i][j] + b.vals[i][j];

  return sum;
}