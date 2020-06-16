#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#include "arith.h"

#define N 1024

int main(void)
{
    char s[N] = "3+2*2-4*2";
    double result;

    compute(s, &result);

    printf("%lf", result);

    return 0;
}