#include "libft.h"

int    *ft_addition_long_arithmetic(int *x, int *y)
{
    int *result;
    int i;

    i = 1100 - 1;
    result = ft_make_zero_str(1100);
    while (i >= 0)
    {
        result[i] = result[i] + x[i] + y[i];
        if ((result[i] >= 10) && (i != 0))
        {
            result[i - 1] = result[i - 1] + 1;
            result[i] = result[i] % 10;
        }
        i--;
    }
    return(result);
}