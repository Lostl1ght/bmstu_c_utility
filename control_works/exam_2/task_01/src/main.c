#include "bit_pack.h"
#include <stdio.h>

int main(void)
{
    uint32_t num;
    char a, b, c, d;
    num = pack_symbols('K', 'E', 'K', 'W');
    unpack_symbols(num, &a, &b, &c, &d);
    printf("Symbols: %c %c %c %c, size: %zu\n", a, b, c, d, sizeof num);

    four_symb_t num1;
    num1.first = 'K';
    num1.second = 'E';
    num1.third = 'K';
    num1.fourth = 'W';
    printf("Symbols: %c %c %c %c, size: %zu\n", num1.first, num1.second, num1.third, num1.fourth, sizeof num1);
    return 0;
}
