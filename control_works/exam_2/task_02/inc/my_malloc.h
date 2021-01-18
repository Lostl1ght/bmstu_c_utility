#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stdio.h>

struct block_t
{
    size_t size;
    int free;
    struct block_t *next;
};

void* my_malloc(size_t size);
void my_free(void *ptr);

#endif //MY_MALLOC_H
