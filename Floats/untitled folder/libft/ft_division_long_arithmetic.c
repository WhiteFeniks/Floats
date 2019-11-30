#include "libft.h"

int *ft_copy_array(const int *x)
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

int ft_comparison(const int *x, const int *y)
{
    int i;
    int *result;
    int *temp;

    i = 0;
    result = ft_make_zero_str(1100);
    temp = ft_copy_array(x);
    result = ft_difference_long_arithmetic(x, y);
    x = ft_copy_array(temp);
    while(i < 1100)
    {
        if (result[i] < 0)
            return (0);
        i++;
    }
    return (1);
}

int *ft_multiplication(const int *x, const int *y)
{
    int i;
    int j;
    int *result;

    i = 0;
    result = ft_make_zero_str(1100);
    while (y[i] == 0)
        i++;
    j = 1099;
    while (j >= i)
    {
        result[j] = result[j] + y[j] * x[1099];
        if (result[j] > 10)
        {
            result[j - 1] = result[j] / 10;
            result[j] = result[j] % 10;
        }
        j--;
    }
    return (result);
}

int ft_work(int *x)
{
    int i;

    i = 0;
    while(x[i] == 0 && i < 1100)
        i++;
    if (i == 1100)
        return (0);
    else
        return (1);
}

int    *ft_division_long_arithmetic(int *x, int *y)
{
    int *result_divider;
    int len;
    int *res_mult;
    int len_sdwig;
    int i;
    int j;

    j = 0;
    len = (ft_array_length(y) - ft_array_length(x));
    len_sdwig = len;
    x = ft_shift_elements_left(x, len);
    result_divider = ft_make_zero_str(1100);
    while(ft_work(x) > 0)
    {
        if (result_divider[j] == 999)
        {
            result_divider[j] = 0;
            j++;
        }
        len = (ft_array_length(y) - ft_array_length(x));
        x = ft_shift_elements_left(x, len);
        if (ft_comparison(x, y) < 1 && len == 0)
            x = ft_shift_elements_left(x, 1);
        if ((ft_comparison(x, y) < 1 && len == 1))
        {
            result_divider[j + 1] = 999;
            x = ft_shift_elements_left(x, 1);
        }
        i = 1;
        res_mult = ft_make_zero_str(1100);
        while (ft_comparison(x, res_mult) > 0)
        {
            res_mult = ft_make_zero_str(1100);
            res_mult[1099] = i;
            res_mult = ft_multiplication(res_mult, y);
            if (ft_comparison(x, res_mult) > 0)
                i++;
            else
                break;
        }
        result_divider[j] = i - 1;
        x = ft_difference_long_arithmetic(x, ft_difference_long_arithmetic(res_mult, y));
        j++;
    }
    ft_shift_elements_right(result_divider, len_sdwig);
    return (result_divider);
}