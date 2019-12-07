#include "floats.h"

int	*ft_addition_long_arithmetic(int *x, int *y, int accuracy)
{
    int *result;
    int i;
    int j;
    int static count = 0;
    count++;
    i = accuracy - 1;
    j = accuracy - 1;
    result = ft_make_zero_str(accuracy);
    while (i != -1)
    {
        result[i] += x[j] + y[j];
        while (result[i] >= 10)
        {
            result[i - 1] = result[i] / 10;
            result[i] = result[i] % 10;
        }
        i--;
        j--;
    }
    printf("count %d\n", count++);
    printf("%p\n", &x);
    return (result);
}