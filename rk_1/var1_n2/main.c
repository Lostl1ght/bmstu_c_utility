#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define NMAX 64

long input_matrix(long m[NMAX][NMAX], size_t rows, size_t columns);
long output_matrix(long m[NMAX][NMAX], size_t rows, size_t columns);

int main(void)
{
    long m[NMAX][NMAX];
    size_t r, c;
    
    if (scanf("%zu", &r) != 1 || r == 0 || r > 64)
        return EXIT_FAILURE;
    if (scanf("%zu", &c) != 1 || c == 0 || c > 64)
        return EXIT_FAILURE;

    input_matrix(m, r, c);
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

long output_matrix(long m[NMAX][NMAX], size_t rows, size_t columns)
{
    size_t i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
            printf("%ld ", m[i][j]);
        puts("");
    }

    return EXIT_SUCCESS;
}