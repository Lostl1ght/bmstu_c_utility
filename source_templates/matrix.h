#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define NMAX_R 32
#define NMAX_C 32

typedef long matrix_t[NMAX_R][NMAX_C];

long input_matrix(matrix_t a, size_t rows, size_t columns);
void output_matrix(matrix_t a, size_t rows, size_t columns);

#endif