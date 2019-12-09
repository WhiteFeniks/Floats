#include "libft.h"
#include <stdio.h>

int	*ft_addition_long_arithmetic(int **x, int *y, int accuracy)
{
    int *result;
    int i;
    int j;

    i = accuracy - 1;
    j = accuracy - 1;
    result = ft_make_zero_str(accuracy);
    while (i != -1)
    {
        result[i] += *x[j] + y[j];
        while (result[i] >= 10)
        {
            result[i - 1] = result[i] / 10;
            result[i] = result[i] % 10;
        }
        i--;
        j--;
    }
    free(x);
    return (result);
}