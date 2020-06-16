#include "arith.h"
#include <string.h>

#include <stdio.h>

int compute(const char *s, double *result)
{
    size_t len, i;
    double num1, num2, num3;
    char oper1, oper2;
    len = strlen(s);
    i = 0;

    num1 = 0.0;
    oper1 = '+';
    while (i < len)
    {
        num2 = get_num(s, &i);
        oper2 = s[i];
        i++;
        compute_prod(&oper2, &num2, &num3, &i, s);
        if (oper1 == '+')
            num1 += num2;
        else if (oper1 == '-')
            num1 -= num2;
        oper1 = oper2;
    }

    *result = num1;
    return 0;
}

int get_num(const char *s, size_t *i)
{
    size_t j = 0;
    int num;
    char num_s[INT_LEN];
    while (s[*i] != '\0' && s[*i] != '+' && s[*i] != '*' && s[*i] != '/')
    {
        if (j > 0 && s[*i] == '-')
            break;
        num_s[j] = s[*i];
        j++;
        (*i)++;
    }
    num_s[j] = '\0';
    num = atoi(num_s);
    return num;
}

void compute_prod(char *oper2, double *num2, double *num3, size_t *i, const char *s)
{    
    while (*oper2 == '*' || *oper2 == '/' )
    {
        *num3 = get_num(s, i);
        if (*oper2 == '*')
            *num2 *= *num3;
        else if (*oper2 == '/')
            *num2 /= *num3;
        *oper2 = s[*i];
        (*i)++;
    }
}