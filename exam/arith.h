#ifndef ARITH_H
#define ARITH_H

#include <stdlib.h>

#define INT_LEN 12

int compute(const char *s, double *result);
int get_num(const char *s, size_t *i);
void compute_prod(char *oper2, double *num2, double *num3, size_t *i, const char *s);
int check(const char *s);

#endif