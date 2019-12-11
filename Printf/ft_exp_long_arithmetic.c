#include "floats.h"

int    *ft_exp_long_arithmetic(int power)
{
    int *result;
    int *tmp;

    result = ft_make_zero_str(1100);
    result[1100 - 1] = 2;
    if (power == 0)
    {
        result[1099] = 1;
        return (result);
    }
    while (power-- > 1)
    {
        tmp = result;
        result = ft_addition_long_arithmetic(result, result, 1100);
        free(tmp);
    }
    return (result);
}