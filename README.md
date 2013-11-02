# mtx.c

``` c
Matrix A = read("./a.mtx");
Matrix B = read("./b.mtx");

printf("Determinant of A: %.3f", det(A));

Matrix mult = multiply(A, B);
write(mult, "./mult.mtx");
```

__Mtx__ is a library in C that makes it easy to read, write, create matrices and do basic and not so basic operations on them. It tries to follow the convenctions used in [MATLAB](http://www.mathworks.com/products/matlab/examples.html?file=/products/demos/shipping/matlab/intro.html) for dealing with matrices.

## Types

#### Values
The `Values` type is a dynamically allocated 2-dimensional array of __doubles__ (for now, in the future could be possible to use different types), that is used to store the values of matrices and vectors.

#### Matrix
This type is the main one used in most functions when dealing with matrices.
``` c
struct Matrix {
  int n;       // Number of rows in the matrix
  int m;       // Number of columns in the matrix
  Values vals; // The values of the matrix 
}
```

#### Row
This type is used when we get or operate on a single row.
``` c
struct Row {
  int n;       // The size of the row
  Values vals; // The values in the row
}
```

## Read
You can read matrices from files, but one file can only contain one matrix.
For example a 3 by 3 matrix in the file `a.mtx` (the .mtx is not required. just makes thing more clear) looks like this:
```
[2 3 4; 2 1 0; 0 0 1]
```
And you can read this matrix with the `read` function:
``` c
Matrix a = read("./a.mtx");
```

## Write
You can write matrices to files in the same fashion just as easily.
``` c
write(A, "./a.mtx");
```

## Functions

#### Create
Returns an _n_ by _m_ matrix initialized with `0`s. The data is dynamically allocated in the heap.
``` c
Matrix create(int n, int m);
```

#### Identity
Returns an _n_ by _m_ `identity` matrix.
``` c
Matrix identity(int n, int m);
```

#### Add
Adds matrix B to A if possible and returns the added matrix. If addition is not possible, `error` is thrown (or nothing happens).
``` c
Matrix add(Matrix A, Matrix B);
```

#### Scale
Scales matrix `A` by `lamba`. The calculation is done on the passed in matrix.
``` c
void scale(Matrix A, double lambda);
```

#### Multiply
Multiplies matrix `A` by matrix `B` and returns the result. If multiplication is not possible, `error` is thrown.
``` c
Matrix multiply(Matrix A, Matrix B);
```

#### Exchange
Exchanges rows `i` and `j` in matrix `A`.
``` c
void exchange(Matrix *A, int i, int j);
```

#### row
Returns the `ith` row of matrix `A`.
``` c
Row row(Matrix A, int i);
```

#### scale_row
Scales row `r` by `lambda`.
``` c
void scale_row(Row r, double lambda);
```

#### add_row
Adds row `r` to the `ith` row of matrix `A`.
``` c
void add_row(Row r, int i, Matrix A);
```

#### rref
Makes matrix `A` into __reduced row echelon form__.
``` c
void rref(Matrix A);
```

#### rank
Returns the rank of matrix `A`.
``` c
int rank(Matrix A);
```

#### dim
Returns the dimension of matrix `A`.
``` c
int dim(Matrix A);
```

#### transpose
Transposes matrix `A`.
``` c
void transpose(Matrix A);
```

#### det
Calculates the determinant of matrix `A`.
``` c
double det(Matrix A);
```

#### dup
Duplicates matrix `A`.
``` c
Matrix dup(Matrix A);
```

## Roadmap
These are other important functions that could be done later.

#### inv
Calculates the inverse of matrix `A`.
``` c
Matrix inv(Matrix A);
```

#### eig
Calculates the eigenvalues of matrix `A`.
``` c
double[] eig(Matrix A);
```