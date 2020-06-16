#include "arith.h"
#include <string.h>

#include <stdio.h>


// int compute(char *s, double *result)
// {
//     //22+3*2
//     size_t len, i;
//     double num1, num2, num3;
//     len = strlen(s);
//     i = 0;

//     num1 = get_num(s, &i);    
//     while (i < len)
//     {

//     }

//     *result = 0;
//     return 0;
// }

int get_num(char *s, size_t *i)
{
    size_t j = 0;
    int num;
    char num_s[INT_LEN];
    while (s[*i] != '\0' && s[*i] != '+' && s[*i] != '*' && s[*i] != '/')
    {
        if (j > 0  && s[*i] == '-')
            break;
        num_s[j] = s[*i];
        j++;
        (*i)++;
    }
    num_s[j] = '\0';
    num = atoi(num_s);
    return num;
}