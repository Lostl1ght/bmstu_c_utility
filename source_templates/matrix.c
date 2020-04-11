#include "matrix.h"

long input_matrix(matrix_t a, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (scanf("%ld", &a[i][j]) != 1)
                return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

long output_matrix(matrix_t a, size_t rows, size_t columns)
{
    size_t i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
            printf("%ld ", a[i][j]);
        puts("");
    }

    return EXIT_SUCCESS;
}