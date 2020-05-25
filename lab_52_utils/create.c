#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <string.h>

#include "struct.c"

int create(FILE *f);
int input_string(char *s, long smax);
int print(FILE *f);
int file_size(FILE *f, size_t *size);

int main(int argc, char **argv)
{
    FILE *f1;
    if (argc != 2)
        return 1;
    f1 = fopen(argv[1], "wb");
    while (!create(f1));
    fclose(f1);

    // f1 = fopen(argv[1], "rb");
    // print(f1);
    // fclose(f1);
    
    // FILE *f2;
    // f2 = fopen("data1.bin", "rb");
    // puts("\n");    
    // print(f2);    
    // fclose(f2);

    return 0;
}

int create(FILE *f)
{
    goods_t good;
    printf("Input name: ");
    if (input_string(good.name, MAX_NAME) == 2)
        input_string(good.name, MAX_NAME);
    if (strcmp(good.name, "stop") == 0)
        return 1;
    printf("Input producer: ");
    input_string(good.prod, MAX_PROD);
    printf("Input price: ");
    scanf("%" PRIu32, &good.price);
    printf("Input count: ");
    scanf("%" PRIu32, &good.count);
    fwrite(&good, sizeof(good), 1, f);
    return 0;
}

int input_string(char *s, long smax)
{
    long len;
    long i;
    if (fgets(s, smax + 1, stdin) == NULL)
        return 1;
    len = strlen(s);
    if (len == smax && s[smax - 1] != '\n')
        return 1;
    i = 0;
    while (s[i])
    {
        if (s[i] == '\n')
            s[i] = '\0';
        i++;
    }
    len = strlen(s);
    if (len == 0)
        return 2;
    return 0;
}

int print(FILE *f)
{
    size_t size;
    goods_t good;
    if (file_size(f, &size) || size < sizeof(goods_t))
        return 1;
    else
    {
        for (size_t i = 0; i < size / sizeof(int); i++)
            if (fread(&good, sizeof(goods_t), 1, f) == 1)
                good_output(&good);
            else
                return 1;
    }
    return 0;
}

int file_size(FILE *f, size_t *size)
{
    long sz;
    if (fseek(f, 0, SEEK_END))
        return 1;
    sz = ftell(f);
    if (sz < 0)
        return 1;
    *size = sz;
    fseek(f, 0, SEEK_SET);
    return 0;
}
