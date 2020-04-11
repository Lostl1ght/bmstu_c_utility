#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "array.h"


int main(void)
{
    size_t l;
    scanf("%zu", &l);
    printf("%zu", 10 * l);

    return EXIT_SUCCESS;
}