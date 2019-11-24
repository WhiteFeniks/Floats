#include "libft.h"

int ft_shift_one(int len)
{
    int result;

    if (len == 0)
        return (1);
    result = 10;
    while (--len > 0)
        result = result * 10;
    return (result);
}

int	ft_array_length(int *my_array)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(my_array[i] == 0)
        i++;
    while (i < 1100)
    {
        i++;
        count++;
    }
    return (count);
}

int ft_align_digital(int digital)
{
    digital = digital * 10;
    return (digital);
}

int    *ft_division_long_arithmetic(int *x, int *y)
{
    int number_1;
    int number_2;
    int *result;
    int i;
    int len;
    int flag;

    i = 0;
    flag = 0;
    result = ft_make_zero_str(1100);
    len = (ft_array_length(y) - ft_array_length(x));
    x = ft_shift_elements_left(x, len + 1);
    number_1 = ft_make_number(x);
    number_2 = ft_make_number(y);
    while (number_1 % number_2 != 0)
    {
        while (number_1 / number_2 <= 0)
        {
            flag++;
            number_1 = ft_align_digital(number_1);
        }
        if (flag > 1)
            i++;
        result[i++] = number_1 / number_2;
        number_1 = number_1 % number_2;
        flag = 0;
    }
    ft_shift_elements_right(result, len);
    return (result);
}