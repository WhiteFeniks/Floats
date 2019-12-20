#include "libft.h"

int	*ft_difference_long_arithmetic(int *x, int *y, int accuracy)
{
    int i;
    int *result;
    int *temp;

    i = accuracy - 1;
    result = malloc(sizeof(int) * accuracy);
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