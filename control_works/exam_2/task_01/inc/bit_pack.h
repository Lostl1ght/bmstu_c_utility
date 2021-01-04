#ifndef BIT_PACK_H
#define BIT_PACK_H

#include <inttypes.h>

uint32_t pack_symbols(char a, char b, char c, char d);

void unpack_symbols(uint32_t num, char *a, char *b, char *c, char *d);

#endif //BIT_PACK_H
