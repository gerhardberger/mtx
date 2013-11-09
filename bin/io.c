/*

  io.c
  Created by Hegyi Gellért on 10/08/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/


/*
  Read
*/
Matrix read (char *filename) {
  // Open file for counting rows and columns
  FILE *fp = fopen(filename, "r");
  
  // If cannot open file
  assert(fp != NULL);

  char c;
  Value n;
  Index row_size = 1, col_size = 1, col_size_ = 0;
  while (fscanf(fp, "%c%lf", &c, &n) != EOF) {
    if (c == ';') {
      col_size_ = col_size;
      col_size = 1;
      row_size++;
    }
    if (c == ' ') col_size++;
  }

  fclose(fp);

  // Reading the file again to get the values
  Matrix m = create(row_size, col_size);

  Index i = 0;
  Index j = 0;
  fp = fopen(filename, "r");
  while (fscanf(fp, "%c%lf", &c, &n) != EOF) {
    if (c == ';') m.vals[++i][j = 0] = n;
    if (c == ' ' || c == '[') m.vals[i][j++] = n;
  }

  fclose(fp);

  return m;
}


/*
  Write
*/
int write (Matrix A, char *filename) {
  // Open file for writing
  FILE *fp = fopen(filename, "w");

  if (fp == NULL) return 0;

  fprintf(fp, "[");
  Index i, j;
  for (i = 0; i < A.n; ++i) {
    for (j = 0; j < A.m; ++j)
      if (j < A.n - 1) fprintf(fp, "%f ", A.vals[i][j]);
      else fprintf(fp, "%f", A.vals[i][j]);
    if (i < A.n - 1) fprintf(fp, "; ");
  }
  fprintf(fp, "]");

  fclose(fp);
  return 1;
}