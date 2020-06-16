#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#include "arith.h"

#define N 1024

int main(void)
{
    char s[N] = "3+2*2*2+4*-2";
    double result;

    if (compute(s, &result))
        return EXIT_FAILURE;

    printf("%lf", result);

    return EXIT_SUCCESS;
}