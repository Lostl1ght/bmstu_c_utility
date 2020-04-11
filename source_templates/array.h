#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define NMAX 32

typedef long array_t[NMAX];

long input_array(array_t a, size_t n);
long output_array(array_t a, size_t n);
long sort_array(array_t a, size_t n);

#endif