#include <stdio.h>
#include "my_malloc.h"

int main(void)
{
    int *i = my_malloc(sizeof *i);
    *i = 1234;
    printf("%d", *i);
    my_free(i);
    return 0;
}
