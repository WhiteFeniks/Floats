/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_division_long_arithmetic.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:03:29 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 21:03:31 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 5. Функция умножения числа на 10
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
** 4. Функция очистки x и возврат result
*/

int     *ft_free_x(int *x, int *result)
{
    free(x);
    return (result);
}

/*
** 3. Функция проверки массива на числа отличные от нуля, чтобы
** в посследствии понять дошли ли мы до конца или нет
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
** 2. Функция очистки temp1 и последующее перепресвоение
*/

void    ft_free_my(int **temp1, int *result)
{
    free(*temp1);
    *temp1 = result;
}

/*
** 1. Функция деления числа х на у. Аccuracy - точность = 1100.
** Numb_of_zero - количество нулей которые нужно записать
** справа от 1, вынесена вверх, чтобы уместить в 25 строк.
** Сначала выравниваем массив x по сравнению с y, добавляя нули справа
** Потом начинаем увеличивать элемент res[numb_of_zero] до тех пор, пока temp
** не станет больше x. После делаем на одно вычитание из temp - y,
** т.к. нам нужен предыдущий результат. И из х вычитаем полученный до этого
** temp. Проверяем на то, закончились ли цифры в х
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
