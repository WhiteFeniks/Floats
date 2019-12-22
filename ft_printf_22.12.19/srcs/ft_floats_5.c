/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:32:57 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 23:59:44 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 5. Функция округления дробной части
*/

void	ft_round_fract(int **fractional_part, long long int acc)
{
	int i;

	i = 0;
	if (fractional_part[i][acc] >= 5)
		fractional_part[i][acc - 1] += 1;
	while (acc > 0)
	{
		while (fractional_part[i][acc] == 10)
		{
			fractional_part[i][acc - 1] = fractional_part[i][acc - 1]
				+ fractional_part[i][acc] / 10;
			fractional_part[i][acc] = fractional_part[i][acc] % 10;
		}
		acc--;
	}
}

/*
** 4.Функиця округления числа, если точность = 0
*/

void	ft_zero_accuracy(int **integer_part, int **fractional_part)
{
	int acc;
	int i;

	i = 0;
	acc = 1099;
	if (fractional_part[i][0] == 5)
	{
		if (integer_part[i][acc] % 2 != 0)
			integer_part[i][acc] += 1;
	}
	if (fractional_part[i][0] > 5)
	{
		integer_part[i][acc] += 1;
	}
	while (integer_part[i][acc] == 10)
	{
		integer_part[i][acc - 1] = integer_part[i][acc - 1]
			+ integer_part[i][acc] / 10;
		integer_part[i][acc] = integer_part[i][acc] % 10;
		acc--;
	}
}

/*
** 3. Функция округления числа + функции окргления дробной и целой части
*/

void	ft_sps_polina(int **int_part, int **fract_part,
	long long int acc, int i)
{
	i = 0;
	if (acc == 0)
		ft_zero_accuracy(int_part, fract_part);
	ft_round_fract(fract_part, acc);
	acc = 1099;
	while (acc > 0)
	{
		if (fract_part[i][0] == 10)
		{
			if (acc == 1099)
			{
				int_part[i][acc] += 1;
				fract_part[i][0] = 0;
			}
			while (int_part[i][acc] == 10)
			{
				int_part[i][acc - 1] = int_part[i][acc - 1]
					+ int_part[i][acc] / 10;
				int_part[i][acc] = int_part[i][acc] % 10;
				acc--;
			}
		}
		acc--;
	}
}

/*
** 2. Функция проверяющая порядок на наличие чисел != 1 для проверки inf
*/

int		check_inf_order(t_floats **new)
{
	int i;

	i = 0;
	while (i < 15)
	{
		if ((*new)->order[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

/*
** 1. Функция проверяющая мантиссу на наличие чисел != 0 для проверки inf
*/

int		check_inf_mantissa(t_floats **new)
{
	int i;

	i = 0;
	while (i < 65)
	{
		if ((*new)->mantissa[i] != 0)
			return (0);
		i++;
	}
	return (1);
}
