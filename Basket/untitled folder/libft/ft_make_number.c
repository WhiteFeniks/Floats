#include "libft.h"

int my_shift_one(int len)
{
    long long result;

    if (len == 0)
        return (1);
    result = 10;
    while (--len > 0)
        result = result * 10;
    return (result);
}

int ft_make_number(int *y)
{
    int i;
    long long num;

    i = 0;
    num = 0;
    while (y[i] == 0)
        i++;
    while (i < 1100)
    {
        num = num + y[i] * my_shift_one(1100 - i - 1);
        i++;
    }
    return (num);
}