#include "bit_pack.h"

uint32_t pack_symbols(char a, char b, char c, char d)
{
    uint32_t num;
    num = (a << 24) | (b << 16) | (c << 8) | d;
    return num;
}

void unpack_symbols(uint32_t num, char *a, char *b, char *c, char *d)
{
    *d = num & 0xFF;
    *c = (num >> 8) & 0xFF;
    *b = (num >> 16) & 0xFF;
    *a = (num >> 24) & 0xFF;
}
