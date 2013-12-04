/*

  ops.c
  Created by Hegyi Gellért on 10/08/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/
#include <string.h>


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
Matrix add (Matrix *a, Matrix *b) {
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
void scale (Matrix *m, Value lambda) {
  Index i, j;

  for (i = 0; i < m->n; ++i)
    for (j = 0; j < m->m; ++j)
      m->vals[i][j] *= lambda;

}


/*
  Multiply
*/
Matrix multiply (Matrix *a, Matrix *b) {
  // Check if multiplication is possible
  assert(a->m == b->n);

  Matrix m = create(a->n, b->m);

  Index i, j;
  for (i = 0; i < m.n; ++i)
    for (j = 0; j < m.m; ++j)
      m.vals[i][j] = _multipliedValue(i, j, a, b);

  return m;
}


/*
  Exchange
*/
void exchange (Matrix *m, Index ith, Index jth) {
  // Checking that the ith and jth are in range
  assert(ith <= m->n && jth <= m->n);

  Index i, j;
  Value tmp;

  for (i = 0; i < m->m; ++i) {
    tmp = m->vals[ith][i];
    m->vals[ith][i] = m->vals[jth][i];
    m->vals[jth][i] = tmp;
  }
}


/*
  Row
*/
Row row (Matrix *m, Index i) {
  assert(i <= m->n);
  Row r;
  r.n = m->m;
  r.vals = malloc(r.n * sizeof(Value));
  handleAllocError(r.vals);

  memcpy(r.vals, m->vals[i], r.n * sizeof(Value));

  return r;
}


/*
  Scale row
*/
void scale_row (Row *r, double lambda) {
  Index i;
  for (i = 0; i < r->n; ++i)
    r->vals[i] *= lambda;
}


/*
  Scale matrix row
*/
void scale_mtx_row (Matrix *m, Index ith, Value lambda) {
  Index i;
  for (i = 0; i < m->m; ++i)
    m->vals[ith][i] *= lambda;
}


/*
  Add row
*/
void add_row (Row *r, Index i, Matrix *m) {
  assert(i <= m->n && r->n == m->m);
  Index j;
  for (j = 0; j < m->m; ++j)
    m->vals[i][j] += r->vals[j];
}


void _fixPivot (Matrix *m, Index ith, Index *col) {
  if (ith == m->n - 1 || m->vals[ith][*col] != 0) return;
  Index i, ith_ = ith;
  for (i = ith_ + 1; i < m->n; ++i) {
    if (m->vals[i][*col] != 0) {
      exchange(m, i, ith_);
      ith_++;
      if (m->vals[ith_][*col] != 0) break;
    }
  }
  for (i = *col; i < m->m && _eqZero(m->vals[ith][i]); ++i) ;
  *col = i;
}

void _cleanDown (Matrix *m, Index ith, Index jth) {
  if (ith == m->n - 1) return;
  Index i;
  Value prev = 1;
  for (i = ith + 1; i < m->n; ++i) {
    Row r = row(m, ith);
    scale_row(&r, prev * -1 * m->vals[i][jth]);
    add_row(&r, i, m);
  }
}

void _cleanUpZeros (Matrix *m) {
  Index i, j;
  for (i = 0; i < m->n; ++i)
    for (j = 0; j < m->m; ++j)
      if (_eqZero(m->vals[i][j])) m->vals[i][j] = 0;
}

/*
  rref
*/
void rref (Matrix *m) {
  Index i;
  Values v = m->vals;

  for (i = 0; i < m->n; ++i) {
    Index col = i;

    _fixPivot(m, i, &col);
    if (col == m->m || _eqZero(v[i][col])) break;

    scale_mtx_row(m, i, 1 / v[i][col]);

    _cleanDown(m, i, col);
  }

  _cleanUpZeros(m);

  m->inrref = 1;
}


/*
  rank
*/
Index rank (Matrix *m) {
  if (!m->inrref) {
    Matrix m_ = dup(m);
    m = &m_;
    rref(m);
  }

  Index i, j, rk = 0;
  for (i = 0; i < m->n; ++i) {
    for (j = 0; j < m->m && _eqZero(m->vals[i][j]); ++j) ;
    if (j < m->m) rk++;
  }

  return rk;
}


/*
  dim
*/
Index dim (Matrix *m) {
  return rank(m);
}