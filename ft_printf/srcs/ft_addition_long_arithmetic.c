/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addition_long_arithmetic.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:13:42 by bglover           #+#    #+#             */
/*   Updated: 2019/12/22 05:23:00 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	*ft_addition_long_arithmetic(int *a, int *b, int acc)
{
	int *rez;
	int i;
	int j;

	i = acc - 1;
	j = acc - 1;
	rez = ft_intstr(acc);
	while (i != -1)
	{
		rez[i] += a[j] + b[j];
		while (rez[i] >= 10)
		{
			rez[i - 1] = rez[i] / 10;
			rez[i] = rez[i] % 10;
		}
		i--;
		j--;
	}
	return (rez);
}
