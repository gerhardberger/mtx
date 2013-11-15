/*

  ops.h
  Created by Hegyi Gellért on 11/14/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/
#include "ops.c"


/*
  Add

  Adds matrix B to A if possible and returns the added matrix.
  If addition is not possible, `error` is thrown (or nothing
  happens).
*/
Matrix add(Matrix *A, Matrix *B);


/*
  Scale

  Scales matrix A by lambda. The calculation is done on the
  passed in matrix.
*/
void scale(Matrix *A, double lambda);


/*
  Multiply

  Multiplies matrix `A` by matrix `B` and returns the result.
  If multiplication is not possible, `error` is thrown.
*/
Matrix multiply(Matrix *A, Matrix *B);