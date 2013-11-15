/*

  ops.c
  Created by Hegyi Gellért on 10/08/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/

Value _multipliedValue (Index i, Index j, Matrix *a, Matrix *b) {
  Index k, l;
  Value v = 0;
  for (k = 0; k < a->m; ++k)
    v += a->vals[i][k] * b->vals[k][j];

  return v;
}


/*
  Add
*/
Matrix add(Matrix *a, Matrix *b) {
  // Throw error if sizes are not equal
  assert(a->n == b->n && a->m == b->m);

  Matrix sum = create(a->n, a->m);
  Index i, j;
  for (i = 0; i < sum.n; ++i)
    for (j = 0; j < sum.m; ++j)
      sum.vals[i][j] = a->vals[i][j] + b->vals[i][j];

  return sum;
}


/*
  Scale
*/
void scale(Matrix *m, Value lambda) {
  Index i, j;

  for (i = 0; i < m->n; ++i)
    for (j = 0; j < m->m; ++j)
      m->vals[i][j] *= lambda;

}


/*
  Multiply
*/
Matrix multiply(Matrix *a, Matrix *b) {
  // Check if multiplication is possible
  assert(a->m == b->n);

  Matrix m = create(a->n, b->m);

  Index i, j;
  for (i = 0; i < m.n; ++i)
    for (j = 0; j < m.m; ++j)
      m.vals[i][j] = _multipliedValue(i, j, a, b);

  return m;
}

