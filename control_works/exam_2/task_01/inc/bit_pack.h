#ifndef BIT_PACK_H
#define BIT_PACK_H

#include <inttypes.h>

typedef struct
{
    unsigned int first : 8;
    unsigned int second : 8;
    unsigned int third : 8;
    unsigned int fourth : 8;
} four_symb_t;

uint32_t pack_symbols(char a, char b, char c, char d);

void unpack_symbols(uint32_t num, char *a, char *b, char *c, char *d);

#endif //BIT_PACK_H
