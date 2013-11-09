/*

  io.c
  Created by Hegyi Gellért on 10/08/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
  Read
*/
Matrix read (char *filename) {
  // Open file for counting rows and columns
  FILE *fp = fopen(filename, "r");
  
  // If cannot open file
  assert(fp != NULL);

  Matrix m;
  char c;
  Value n;
  Index row_size = 1, col_size = 1, col_size_ = 0;
  while (fscanf(fp, "%c%lf", &c, &n) != EOF) {
    if (c == ';') {
      // Assert row size is equal to the last one
      //if (col_size_ > 0) assert(col_size_ == col_size);
      col_size_ = col_size;
      col_size = 1;
      row_size++;
    }
    if (c == ' ') col_size++;
  }
  // Assert last row size is equal to the others
  //assert(col_size_ == col_size);


  // Reading the file again to get the values
  m.n = row_size;
  m.m = col_size;
  m.vals = malloc(m.n * sizeof(Value *));
  assert(m.vals != NULL);
  Index i;
  for (i = 0; i < m.n; ++i) {
    m.vals[i] = malloc(m.m * sizeof(Value));
    assert(m.vals[i] != NULL);
  }

  i = 0;
  Index j = 0;
  fp = fopen(filename, "r");
  while (fscanf(fp, "%c%lf", &c, &n) != EOF) {
    if (c == ';') m.vals[++i][j = 0] = n;
    if (c == ' ' || c == '[') m.vals[i][j++] = n;
  }

  return m;
}