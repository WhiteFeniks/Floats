#include "ft_printf.h"

/*
** 1. Функция возведения в степени power числа 2. Аccuracy - точность = 1100.
** Numb_of_zero - количество нулей которые нужно записать
** справа от 1, вынесена вверх, чтобы уместить в 25 строк.
*/

int    *ft_exp_long_arithmetic(int power)
{
    int *result;
    int *tmp;
    int accuracy;

    accuracy = 1100;
    result = ft_make_zero_str(accuracy);
    result[accuracy - 1] = 2;
    if (power == 0)
    {
        result[accuracy - 1] = 1;
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