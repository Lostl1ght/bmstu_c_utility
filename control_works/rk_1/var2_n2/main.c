#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define NMAX 64

long input_matrix(long m[NMAX][NMAX], size_t rows, size_t columns);
void output_matrix(long m[NMAX][NMAX], size_t rows, size_t columns);
long abs_sum(long m[NMAX][NMAX], size_t n, size_t j);
void array_of_sums(long m[NMAX][NMAX], long a[NMAX], size_t c, size_t r);
long sort_matrix_by_sum(long m[NMAX][NMAX], long a[NMAX], size_t c, size_t r);
void swap(long *a, long *b);

int main(void)
{
    long m[NMAX][NMAX];
    size_t r, c;
    long a[NMAX];

    if (scanf("%zu", &r) != 1 || r == 0 || r > 64)
        return EXIT_FAILURE;
    if (scanf("%zu", &c) != 1 || c == 0 || c > 64)
        return EXIT_FAILURE;

    if (input_matrix(m, r, c))
        return EXIT_FAILURE;

    array_of_sums(m, a, c, r);

    sort_matrix_by_sum(m, a, c, r);

    output_matrix(m, r, c);

    return EXIT_SUCCESS;

}

long input_matrix(long m[NMAX][NMAX], size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (scanf("%ld", &m[i][j]) != 1)
                return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

void output_matrix(long m[NMAX][NMAX], size_t rows, size_t columns)
{
    size_t i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
            printf("%ld ", m[i][j]);
        puts("");
    }
    return;
}

long abs_sum(long m[NMAX][NMAX], size_t n, size_t j)
{
    if (n == 0)
        return 0;

    long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += labs(m[i][j]);

    return sum;
}

void array_of_sums(long m[NMAX][NMAX], long a[NMAX], size_t c, size_t r)
{
    for (size_t j = 0; j < c; j++)
        a[j] = abs_sum(m, r / 2, j);
}

long sort_matrix_by_sum(long m[NMAX][NMAX], long a[NMAX], size_t c, size_t r)
{
    if (c == 0)
        return EXIT_FAILURE;
    
    for (size_t i = 1; i < c; i++)
    {
        size_t cur = i;
        while (cur > 0 && a[cur] > a[cur - 1])
        {
            swap(a + cur, a + (cur - 1));
            for (size_t k = 0; k < r; k++)
                swap(&m[k][cur], &m[k][cur - 1]);
            cur--;
        }
        
    }
    
    return EXIT_SUCCESS;
}

void swap(long *a, long *b)
{
    long t = *a;
    *a = *b;
    *b = t;

    return;
}