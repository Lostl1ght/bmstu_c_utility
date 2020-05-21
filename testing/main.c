#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>


int main(void)
{
    int a[10];
    int *pa = a, *pb = &a[2]; // int *pa = a, *pb = a + 2;
    printf("%zd", pb - pa); // какой формат?, какое значение?

    return 0;
}