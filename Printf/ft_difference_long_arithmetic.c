#include "floats.h"
/*
** Функция вычитания из массива x, массив y
*/

int	*ft_difference_long_arithmetic(int *x, int *y, int accuracy)
{
    int i;
    int *result;

    i = accuracy - 1;
    result = ft_make_zero_str(accuracy);
    while (i >= 0)
    {
        result[i] = 0;
        i--;
    }
    i = accuracy - 1;
    while (i >= 0)
    {
        if (x[i] < y[i])
        {
            x[i] += 10;
            x[i - 1] -= 1;
        }
        result[i] = x[i] - y[i];
        i--;
    }
    return (result);
}