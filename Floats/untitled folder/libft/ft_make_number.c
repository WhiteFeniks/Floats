#include "libft.h"

int my_shift_one(int len)
{
    int result;

    if (len == 0)
        return (1);
    result = 10;
    while (--len > 0)
        result = result * 10;
    return (result);
}

int ft_make_number(int *my_array)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (my_array[i] == 0)
        i++;
    while (i < 1100)
    {
        num = num + my_array[i] * my_shift_one(1100 - i - 1);
        i++;
    }
    return (num);
}