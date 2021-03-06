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


/*
  Exchange

  Exchanges rows i and j in matrix A.
*/
void exchange(Matrix *A, Index i, Index j);


/*
  Row

  Returns the ith row of matrix A.
*/
Row row(Matrix *A, Index i);


/*
  Scale row

  Scales row r by lambda.
*/
void scale_row(Row *r, double lambda);


/*
  Add row
  
  Adds row r to the ith row of matrix A.
*/
void add_row(Row *r, Index i, Matrix *A);


/*
  rref

  Makes matrix A into Reduced Row Echelon Form.
*/
void rref(Matrix *A);


/*
  Rank
  
  Returns the rank of matrix A.
*/
Index rank(Matrix *A);


/*
  Dim

  Returns the dimension of matrix A.
*/
Index dim(Matrix *A);


/*
  Transpose

  Transposes matrix A.
*/
Matrix transpose(Matrix *A);


/*
  Determinant

  Calculates the determinant of matrix A.
*/
Value det(Matrix *A);