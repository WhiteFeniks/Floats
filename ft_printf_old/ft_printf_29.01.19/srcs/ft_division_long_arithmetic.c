/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_division_long_arithmetic.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:12:02 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 18:02:42 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	numb_of_zeroes(int *div)
{
	int i;

	i = 0;
	while (div[i] == 0)
		i++;
	return (i);
}

int	comparasion(int *a, int *b, int acc)
{
	int i;

	i = 0;
	while (a[i] == 0 && b[i] == 0)
		i++;
	while (a[i] == b[i] && i != acc)
		i++;
	if (i == acc)
		return (1);
	return ((a[i] > b[i]) ? 1 : 0);
}

int	*mult_on_ten(int *num, int i, int acc)
{
	while (i <= acc - 1)
	{
		num[i - 1] = num[i];
		num[i++] = 0;
	}
	return (num);
}

int	st(int *num, int acc)
{
	int i;

	i = 0;
	while (i != acc && num[i] == 0)
		i++;
	return (i);
}

/*
** Функция деления одного числа num на другое div (длинная арфиметика)
*/

int	*ft_division_long_arithmetic(int *num, int *div, int acc, int numb_of_zero)
{
	int i;
	int *rez;
	int *temp;

	rez = ft_make_zero_str(acc);
	numb_of_zero = acc - 2 - numb_of_zeroes(div);
	num[numb_of_zeroes(div) - 1] = 1;
	num[acc - 1] = 0;
	while (++numb_of_zero < acc)
	{
		temp = ft_make_zero_str(acc);
		while (comparasion(num, temp, acc) || --rez[numb_of_zero] == 10)
		{
			rez[numb_of_zero]++;
			temp = ft_division_add_1(&temp, &div, acc);
		}
		temp = ft_division_add_2(&temp, &div, acc);
		num = ft_division_add_3(&num, &temp, acc);
		i = st(num, acc);
		free(temp);
		if (i == acc)
			return (ft_division_free(&num, rez));
		num = mult_on_ten(num, i, acc);
	}
	return (rez);
}
