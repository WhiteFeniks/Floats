#include "floats.h"

/*
** 1. Функция очистки temp1 и последующее перепресвоение
*/

void    ft_free_my(int **temp1, int *result)
{
	free(*temp1);
	*temp1 = result;
}

 /*
 ** 2. Функция умножения числа на 10
 */

int     *mult_on_ten(int *x, int i, int accuracy)
{
    while (i <= accuracy - 1)
    {
        x[i - 1] = x[i];
        x[i++] = 0;
    }
    return (x);
}

/*
 ** 3. Функция проверки массива на числа отличные от нуля, чтобы в посследствии понять дошли ли мы до конца или нет
 */

int     check_end(int *x, int accuracy)
{
    int i;

    i = 0;
    while (i != accuracy && x[i] == 0)
        i++;
    return (i);
}

/*
** 4. Функция очистки x и возврат result
*/

int     *ft_free_x(int *x, int *result)
{
    free(x);
    return (result);
}

/*
** 5. Функция деления числа х на у. аccuracy - точность = 1100. Numb_of_zero - количество нулей которые нужно записать
** справа от 1, вынесена вверх, чтобы уместить в 25 строк.
*/

int     *ft_division_long_arithmetic(int *x, int *y, int accuracy, int numb_of_zero)
{
    int i;
    int *result;
    int *temp;

    result = ft_make_zero_str(accuracy);
    numb_of_zero = accuracy - 2 - numb_of_zeroes(y);
    x[numb_of_zeroes(y) - 1] = 1;
    x[accuracy - 1] = 0;
    while (++numb_of_zero < accuracy)
    {
        temp = ft_make_zero_str(accuracy);
        while (comparasion(x, temp, accuracy) || --result[numb_of_zero] == 999)
        {
            result[numb_of_zero]++;
            ft_free_my(&temp, ft_addition_long_arithmetic(temp, y, accuracy));
        }
        ft_free_my(&temp, ft_difference_long_arithmetic(temp, y, accuracy));
        ft_free_my(&x, ft_difference_long_arithmetic(x, temp, accuracy));
		i = check_end(x, accuracy);
        free(temp);
        if (i == accuracy)
            return (ft_free_x(x, result));
        x = mult_on_ten(x, i, accuracy);
    }
    return (result);
}
