#include "libft.h"

int *my_copy_array(const int *x)
{
    int i;
    int *result;
    result = ft_make_zero_str(1100);

    i = 0;
    while (i < 1100)
    {
        result[i] = x[i];
        i++;
    }
    return (result);
}

int    *ft_difference_long_arithmetic(const int *x, const int *y)
{
    int *result;
    int i;
    int count;
    int *temp;

    i = 0;
    result = ft_make_zero_str(1100);
    while  (x[i] == 0)
        i++;
    count = 1100 - i;
    i = 1100;
    temp = my_copy_array(x);
    while (--i >= (1100 - count))
    {
        if (temp[i] < y[i])
        {
            temp[i] += 10;
            temp[i - 1] -= 1;
        }
        result[i] = temp[i] - y[i];
    }
    result[i] = temp[i];
    return(result);
}