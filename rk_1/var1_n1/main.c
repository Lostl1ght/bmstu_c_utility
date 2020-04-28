#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define NMAX 64

long input_array(long *a, size_t n);
void output_array(long *a, size_t n);
double arithmetic_avg_to_n(long *a, size_t n);
size_t delete_by_avg(long *a, size_t n, double avg);
void delete_by_i(long *a, size_t *n, size_t *i);

int main(void)
{
    long a[NMAX];
    size_t n, p;
    double avg;

    if (scanf("%zu", &n) != 1 || n == 0 || n > 64)
        return EXIT_FAILURE;
    
    if (scanf("%zu", &p) != 1 || p > n)
        return EXIT_FAILURE;

    if (input_array(a, n))
        return EXIT_FAILURE;

    avg = arithmetic_avg_to_n(a, p);

    n = delete_by_avg(a, n, avg);

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

double arithmetic_avg_to_n(long a[NMAX], size_t n)
{
    double sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];
    
    return sum / n;
}

size_t delete_by_avg(long a[NMAX], size_t n, double avg)
{
    for (size_t i = 0; i < n; i++)
        if (a[i] > avg)
            delete_by_i(a, &n, &i);

    return n;
}

void delete_by_i(long a[NMAX], size_t *n, size_t *i)
{
    for (size_t l = *i; l < *n - 1; l++)
        a[l] = a[l + 1];

    *n -= 1;
    *i -= 1;
    return;
}