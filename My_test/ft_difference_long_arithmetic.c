/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_difference_long_arithmetic.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:23:05 by umoff             #+#    #+#             */
/*   Updated: 2019/12/18 15:28:57 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Функция вычитания из массива x, массив y и точностью accuracy
*/

int	*ft_difference_long_arithmetic(int *x, int *y, int accuracy)
{
	int i;
	int *result;

	i = accuracy - 1;
	result = ft_make_zero_str(accuracy);
	while (i >= 0)
	{
		result[i] = 0;
		i--;
	}
	i = accuracy - 1;
	while (i >= 0)
	{
		if (x[i] < y[i])
		{
			x[i] += 10;
			x[i - 1] -= 1;
		}
		result[i] = x[i] - y[i];
		i--;
	}
	return (result);
}
