/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_division_long_arithmetic_2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:03:04 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 21:03:07 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 7. Функция подсчёта количества нулей в массиве числа (делителе)
*/

int numb_of_zeroes(int *divider)
{
    int i;

    i = 0;
    while (divider[i] == 0)
        i++;
    return (i);
}

/*
** 6. Функция сравнения двух массивов
*/

int comparasion(int *x, int *y, int accuracy)
{
    int i;

    i = 0;
    while (x[i] == 0 && y[i] == 0)
        i++;
    while (x[i] == y[i] && i != accuracy)
        i++;
    if (i == accuracy)
        return (1);
    return ((x[i] > y[i]) ? 1 : 0);
}
