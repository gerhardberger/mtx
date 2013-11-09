/*

  util.c
  Created by Hegyi Gellért on 10/09/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/


/*
  Create
*/
Matrix create (Index row_size, Index col_size) {
  Matrix m;

  m.n = row_size;
  m.m = col_size;
  m.vals = malloc(m.n * sizeof(Value *));
  assert(m.vals != NULL);
  Index i;
  for (i = 0; i < m.n; ++i) {
    m.vals[i] = malloc(m.m * sizeof(Value));
    assert(m.vals[i] != NULL);
  }

  return m;
}


/*
  Identity
*/
Matrix identity (Index n) {
  Matrix id = create(n, n);

  Index i, j;
  for (i = 0; i < id.n; ++i) {
    for (j = 0; j < id.n; ++j) {
      id.vals[i][j] = i == j;
    }
  }

  return id;
}