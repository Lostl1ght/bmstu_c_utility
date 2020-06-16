#include "arith.h"
#include <string.h>

#include <stdio.h>


int compute(char *s, double *result)
{
    //22+3*2
    size_t len, p_end;
    long r_num;
    len = strlen(s);
    for (size_t i = len - 1; i > 0; i--)
    {
        if (s[i] == '*' || s[i] == '/')
        {
            r_num = get_right(s + i, &p_end);
            printf("%ld\n", r_num);
        }
    }
    *result = 0;
    return 0;
}

long get_right(char *s, size_t *p_end)
{
    size_t end;
    int c;
    long num;
    end = 2;
    while (s[end] != '\0' && s[end] != '+' && s[end] != '-' && s[end] != '*' && s[end] != '/')
        end++;
    c = s[end + 1];
    s[end + 1] = '\0';
    num = atol(s + 1);
    s[end + 1] = c;
    *p_end = end;
    return num;
}