/*

  util.c
  Created by Hegyi Gellért on 11/09/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/
#include <math.h>


/*
  Handling Alloc Error
*/
void handleAllocError(void *ptr) {
  if (ptr != NULL) return;
  fprintf(stderr, "Some allocation failed!\n");
  assert(0);
}


/*
  Value equals 0
*/
int _eqZero (Value v) {
  return fabs(v) < 10e-8;
}


/*
  Create
*/
Matrix create (Index row_size, Index col_size) {
  Matrix m;

  m.n = row_size;
  m.m = col_size;
  m.inrref = 0;
  m.vals = malloc(m.n * sizeof(Value *));
  handleAllocError(m.vals);
  Index i;
  for (i = 0; i < m.n; ++i) {
    m.vals[i] = malloc(m.m * sizeof(Value));
    handleAllocError(m.vals[i]);
  }

  return m;
}

/*
  Destroy
*/
void destroy (Matrix *m) {
  Index i;
  for (i = 0; i < m->n; ++i)
    free(m->vals[i]);
  free(m->vals);

  m->n = 0;
  m->m = 0;
  m->vals = NULL;
}


/*
  Identity
*/
Matrix identity (Index n) {
  Matrix id = create(n, n);

  Index i, j;
  for (i = 0; i < id.n; ++i)
    for (j = 0; j < id.n; ++j)
      id.vals[i][j] = i == j;

  return id;
}


/*
  Duplicate
*/
Matrix dup(Matrix *a) {
  Matrix b = create(a->n, a->m);
  Index i, j;
  for (i = 0; i < a->n; ++i)
    for (j = 0; j < a->m; ++j)
      b.vals[i][j] = a->vals[i][j];

  return b;
}


/*
  Matrix print
*/
void mtx_print (Matrix *m) {
  printf("Rows: %d\nCols: %d\n", m->n, m->m);
  Index i;
  for (i = 0; i < m->n; ++i) {
    Index j;
    for (j = 0; j < m->m; ++j) printf("%.2f ", m->vals[i][j]);
    printf("\n");
  }
}


/*
  Row print
*/
void row_print (Row *r) {
  printf("Elems: %d\n", r->n);
  Index i;
  for (i = 0; i < r->n; ++i) {
    printf("%.f ", r->vals[i]);
  }
  printf("\n");
}