#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define NMAX 64

long input_matrix(long m[NMAX][NMAX], size_t rows, size_t columns);
void output_matrix(long m[NMAX][NMAX], size_t rows, size_t columns);
void array_of_col_avg(long m[NMAX][NMAX], size_t r, size_t c, double a[NMAX]);
double arithmetic_avg_to_n(long m[NMAX][NMAX], size_t n, size_t j);
void sort_matrix_by_col_avg(double a[NMAX], long m[NMAX][NMAX], size_t r, size_t c);
void lswap(long *a, long *b);
void dswap(double *a, double *b);

int main(void)
{
    long m[NMAX][NMAX];
    size_t r, c;
    double a[NMAX];

    if (scanf("%zu", &r) != 1 || r == 0 || r > 64)
        return EXIT_FAILURE;
    if (scanf("%zu", &c) != 1 || c == 0 || c > 64)
        return EXIT_FAILURE;

    if (input_matrix(m, r, c))
        return EXIT_FAILURE;

    array_of_col_avg(m, r, c, a);

    sort_matrix_by_col_avg(a, m, r, c);

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

void array_of_col_avg(long m[NMAX][NMAX], size_t r, size_t c, double a[NMAX])
{
    for (size_t j = 0; j < c; j++)
        a[j] = arithmetic_avg_to_n(m, r / 2, j);

    return;
}

double arithmetic_avg_to_n(long m[NMAX][NMAX], size_t n, size_t j)
{
    double sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += m[i][j];

    return sum / n;
}

void sort_matrix_by_col_avg(double a[NMAX], long m[NMAX][NMAX], size_t r, size_t c)
{
    for (size_t i = 1; i < c; i++)
    {
        size_t cur = i;
        while (cur > 0 && a[cur] < a[cur - 1])
        {
            dswap(a + cur, a + (cur - 1));
            for (size_t k = 0; k < r; k++)
                lswap(&m[k][cur], &m[k][cur - 1]);
            cur--;
        }
    }

    return;
}

void lswap(long *a, long *b)
{
    long t = *a;
    *a = *b;
    *b = t;

    return;
}

void dswap(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;

    return;
}