/*

  io.c
  Created by Hegyi Gellért on 11/08/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/


/*
  Read
*/
Matrix read (char *filename) {
  // Open file for counting rows and columns
  FILE *fp = fopen(filename, "rt");
  
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

  // Reading the file again to get the values
  Matrix m = create(row_size, col_size);
  Index i = 0;
  Index j = 0;

  // Going back to the beginning of the file
  fseek(fp, 0, SEEK_SET);
  fscanf(fp, "%c%lf", &c, &n);
  m.vals[i][j] = n;
  while (fscanf(fp, "%c%lf", &c, &n) != EOF) {
    if (c == ';') m.vals[++i][j = 0] = n;
    if (c == ' ') m.vals[i][++j] = n;
  }

  fclose(fp);

  return m;
}


/*
  Write
*/
int write (Matrix *A, char *filename) {
  // Open file for writing
  FILE *fp = fopen(filename, "wt");

  if (fp == NULL) return 0;

  fprintf(fp, "[");
  Index i, j;
  for (i = 0; i < A->n; ++i) {
    for (j = 0; j < A->m; ++j)
      if (j < A->n - 1) fprintf(fp, "%f ", A->vals[i][j]);
      else fprintf(fp, "%f", A->vals[i][j]);
    if (i < A->n - 1) fprintf(fp, "; ");
  }
  fprintf(fp, "]");

  fclose(fp);
  return 1;
}