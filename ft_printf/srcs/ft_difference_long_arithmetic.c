/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_difference_long_arithmetic.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:26:38 by bglover           #+#    #+#             */
/*   Updated: 2019/12/22 05:20:33 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	*ft_difference_long_arithmetic(int *a, int *b, int acc)
{
	int i;
	int *rez;

	i = acc - 1;
	rez = malloc(sizeof(int) * acc);
	while (i >= 0)
		rez[i--] = 0;
	i = acc - 1;
	while (i >= 0)
	{
		if (a[i] < b[i])
		{
			a[i] += 10;
			a[i - 1] -= 1;
		}
		rez[i] = a[i] - b[i];
		i--;
	}
	return (rez);
}
