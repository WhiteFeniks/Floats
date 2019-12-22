/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_math_divider.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:47:35 by bglover           #+#    #+#             */
/*   Updated: 2019/10/29 19:21:23 by bglover          ###   ########.fr       */
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
** Длинное деление
*/

int	*ft_long_math_divider(int *num, int *div, int acc, int numb_of_zero)
{
	int i;
	int *rez;
	int *temp;

	rez = ft_intstr(acc);
	numb_of_zero = acc - 2 - numb_of_zeroes(div);
	num[numb_of_zeroes(div) - 1] = 1;
	num[acc - 1] = 0;
	while (++numb_of_zero < acc)
	{
		temp = ft_intstr(acc);
		while (comparasion(num, temp, acc) || --rez[numb_of_zero] == 10)
		{
			rez[numb_of_zero]++;
			temp = ft_first_try(&temp, &div, acc);
		}
		temp = ft_second_try(&temp, &div, acc);
		num = ft_third_try(&num, &temp, acc);
		i = st(num, acc);
		free(temp);
		if (i == acc)
			return (ft_trying_four(&num, rez));
		num = mult_on_ten(num, i, acc);
	}
	return (rez);
}
