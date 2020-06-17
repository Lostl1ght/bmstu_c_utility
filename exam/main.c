#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>

#include "arith.h"

#define N 1024

int main(void)
{
    char s[N];
    double result;

    fgets(s, N, stdin);

    delete_spaces(s);

    if (compute(s, &result))
        return EXIT_FAILURE;

    printf("%lf", result);

    return EXIT_SUCCESS;
}