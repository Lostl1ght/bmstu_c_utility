#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "array.h"

long is_prime(long num)
{
    if (num <= 1)
        return 0;

    long flag = 1;
    for (long i = 2; i <= num / 2; i++) {

        // condition for non-prime
        if (num % i == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main() 
{
    long num, f;
    printf("Enter a positive integer: ");
    scanf("%ld", &num);

    f = is_prime(num);

    if (num == 1) {
        printf("1 is neither prime nor composite.");
    }
    else {
        if (f == 1)
            printf("%ld is a prime number.", num);
        else
            printf("%ld is not a prime number.", num);
    }

    return 0;
}