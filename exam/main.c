#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#include "arith.h"

#define N 1024

int main(void)
{
    char s[N] = "22+3*245";
    double result;

    compute(s, &result);

    return 0;
}