/*

  io.h
  Created by Hegyi Gellért on 11/08/13.
  Copyright (c) 2013 Hegyi Gellért. All rights reserved.

*/
#include "io.c"


/*
  Read

  Reading matrices from files.
*/
Matrix read (char *filename);


/*
  Write

  Writing matrices to files.
*/
int write (Matrix *A, char *filename);