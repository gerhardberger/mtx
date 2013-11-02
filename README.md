# CMatrix

## Types

#### Matrix
This type is the main one used in most functions when dealing with matrices.
``` c
struct Matrix {
  int n;       // Number of rows in the matrix
  int m;       // Number of columns in the matrix
  Values vals; // A 2-dimensional array with the values of the matrix 
}
```

#### Row
This type is used when we get or operate on a single row.
``` c
struct Row {
  int n;       // The size of the row
  Values vals; // The values in the row
}


- Column
{
  n, data
}


## Functions

#### Matrix create(int n, int m)
Returns an _n_ by _m_ matrix initialized with __0__s. The data is dynamically allocated in the heap.

#### Matrix identity(int n, int m)
Returns an _n_ by _m_ __identity__ matrix.

#### Matrix add(Matrix A, Matrix B)
Adds matrix B to A if possible and returns the added matrix. If addition is not possible, __error__ is thrown (or nothing happens).

#### void scale(Matrix *A, double lambda)
Scales matrix __A__ by _lamba_. The calculation is done on the passed in matrix.

#### Matrix multiply(Matrix A, Matrix B)
Multiplies matrix __A__ by matrix __B__ and returns the result. If multiplication is not possible, __error__ is thrown.

#### void exchange(Matrix *A, int i, int j)
Exchanges rows __i__ and __j__ in matrix __A__.

#### Row row(Matrix A, int i)
Returns the __ith__ row of matrix __A__.

#### void scale_row(Row *r, double lambda)
Scales row __r__ by __lambda__.

#### void add_row(Row r, int i, Matrix *A)
Adds row __r__ to the __ith__ row of matrix __A__.

#### void rref(Matrix *A)
Makes matrix __A__ into _reduced row echelon form_.

#### int rank(Matrix A)
Returns the rank of matrix __A__.

#### dim(A)
Returns the dimension of matrix __A__.

#### void transpose(Matrix *A)
Transposes matrix __A__.

#### double det(Matrix A)
Calculates the determinant of matrix __A__.

#### Matrix dup(Matrix A)
Duplicates matrix __A__.



- inv(A)
- eig(A)
