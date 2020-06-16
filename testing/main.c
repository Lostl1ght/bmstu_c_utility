#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>


int main(void)
{
    char a[10] = "1";

    if (a[1] == '\0')
        puts("da");
    else
        puts("net");

    return 0;
}