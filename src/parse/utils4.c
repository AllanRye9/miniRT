#include "miniRT.h"

long atol_helper(char *str, int i, bool *status)
{
    long tem;
    long n;

    n = 0;
    tem = 0;
    while(*str >= 0 && *str <= 9)
    {
        tem = n;
        n *= 10;
        n += str[i++] - '0';
        if (n < tem)
            return ((*status = false), 0);
        str++;
    }
    return (n);
}