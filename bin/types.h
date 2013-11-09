/*

  types.h
  Created by Hegyi Gellért on 10/08/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/


/*
  Index

  The index of the Matrix of Row.
*/
typedef unsigned int Index;


/*
  Value

  The type of the values of the Matrix or Row.
*/
typedef double Value;


/*
  Values

  a dynamically allocated 2-dimensional array of doubles (for now, in
  the future could be possible to use different types), that is used
  to store the values of matrices and vectors.
*/
typedef double **Values;


/*
  Matrix

  This type is the main one used in most functions when dealing with
  matrices.
*/
typedef struct {
  Index n;           // Number of rows in the matrix
  Index m;           // Number of columns in the matrix
  Values vals;       // The values of the matrix 
} Matrix;


/*
  Row

  This type is used when we get or operate on a single row.
*/
typedef struct {
  Index n;           // The size of the row
  Values vals;       // The values in the row
} Row;