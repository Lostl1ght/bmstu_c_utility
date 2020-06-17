#include "arith.h"
#include <string.h>
#include <ctype.h>

int compute(const char *s, double *result)
{
    size_t len, i;
    double num1, num2, num3;
    char oper1, oper2;

    if (check(s))
        return EXIT_FAILURE;

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
    return EXIT_SUCCESS;
}

int get_num(const char *s, size_t *i)
{
    size_t j = 0;
    int num;
    char num_s[INT_LEN];
    while (strchr("+*/", s[*i]) == NULL)
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
    while (*oper2 == '*' || *oper2 == '/')
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

int check(const char *s)
{
    if (isdigit(*s) == 0)
    {
        if (*s != '-')
            return EXIT_FAILURE;
        else if (isdigit(*(s + 1)) == 0)
            return EXIT_FAILURE;
        else
        {
            s++;
            if (check_rest(s))
                return EXIT_FAILURE;
        }
    }
    else if (check_rest(s))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int check_rest(const char *s)
{
    while (*s)
    {
        if (isdigit(*s) == 0)
        {
            if (strchr("+-*/", *s) == NULL)
                return EXIT_FAILURE;
            else if (*(s + 1) != '\0' && *(s + 1) == '-')
            {
                if (*(s + 2) != '\0' && isdigit(*(s + 2)) == 0)
                    return EXIT_FAILURE;
            }
            else if (isdigit(*(s + 1)) == 0)
                return EXIT_FAILURE;
        }
        s++;
    }
    return EXIT_SUCCESS;
}

void delete_spaces(char *s)
{
    char *p;
    size_t len;
    len = strlen(s);
    for (p = s + len - 1; p >= s; p--)
        if (*p == '\n' || *p == ' ')
            while (*p)
            {
                *p = *(p + 1);
                p++;
            }
}