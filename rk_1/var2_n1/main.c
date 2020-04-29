#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 64

long input_array(long a[NMAX], size_t n);
void output_array(long *a, size_t n);
long abs_sum(long a[NMAX], size_t n);
long delete_by_sum(long a[NMAX], size_t n, long sum);
void delete_by_i(long a[NMAX], size_t *n, size_t *i);

int main(void)
{
    long a[NMAX];
    size_t n, p;
    long sum;

    if (scanf("%zu", &n) != 1 || n == 0 || n > 64)
        return EXIT_FAILURE;
    if (scanf("%zu", &p) != 1 || p > n)
        return EXIT_FAILURE;

    if (input_array(a, n))
        return EXIT_FAILURE;

    sum = abs_sum(a, p);

    n = delete_by_sum(a, n, sum);

    output_array(a, n);

    return EXIT_SUCCESS;
}

long input_array(long a[NMAX], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%ld", &a[i]) != 1)
            return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

void output_array(long *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%ld ", a[i]);

    return;
}

long abs_sum(long a[NMAX], size_t n)
{
    if (n == 0)
        return 0;

    long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += labs(a[i]);

    return sum;
}

long delete_by_sum(long a[NMAX], size_t n, long sum)
{
    for (size_t i = 0; i < n; i++)
        if (a[i] > sum)
            delete_by_i(a, &n, &i);

    return n;
}

void delete_by_i(long a[NMAX], size_t *n, size_t *i)
{
    for (size_t k = *i; k < *n - 1; k++)
        a[k] = a[k + 1];

    *n -= 1;
    *i -= 1;
    return;
}