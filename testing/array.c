#include "array.h"

long input_array(array_t a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%ld", &a[i]) != 1)
            return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

long output_array(array_t a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%ld ", a[i]);

    return EXIT_SUCCESS;
}

long sort_array(array_t a, size_t n)
{
    if (n == 0)
        return EXIT_FAILURE;

    for (size_t i = 0; i < n - 1; i++)
    {
        size_t min_i = i;
        for (size_t j = i + 1; j < n; j++)
            if (a[j] < a[min_i])
                min_i = j;

        swap(a + min_i, a + i);
    }
    return EXIT_SUCCESS;
}

long swap(long *a, long *b)
{
    long t = *a;
    *a = *b;
    *b = t;

    return EXIT_SUCCESS;
}
