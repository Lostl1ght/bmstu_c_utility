#include "bit_pack.h"
#include <stdio.h>

int main(void)
{
    uint32_t num;
    num = pack_symbols('K', 'E', 'K', 'W');
    char a, b, c, d;
    unpack_symbols(num, &a, &b, &c, &d);
    printf("Symbols: %c %c %c %c", a, b, c, d);
    return 0;
}
