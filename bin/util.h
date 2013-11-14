/*

  util.h
  Created by Hegyi Gellért on 11/08/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/
#include "util.c"


/*
  Create

  Returns an n by m Matrix. The data is dynamically allocated
  in the heap.
*/
Matrix create (Index row_size, Index col_size);


/*
  Destroy

  Destroys a Matrix (donates the Values back to the heap).
*/
void destroy (Matrix A);



/*
  Identity

  Returns an n by n identity Matrix.
*/
Matrix identity (Index n);