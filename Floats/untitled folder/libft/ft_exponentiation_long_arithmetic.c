#include "libft.h"

int    *ft_exponentiation_long_arithmetic(int power)
{
    int *result;

    result = ft_make_zero_str(1100);
    result[1100 - 1] = 2;
    if (power == 0)
    {
        result[1099] = 1;
        return (result);
    }
    while (power-- > 1)
        result = ft_addition_long_arithmetic(result, result);
    return (result);
}