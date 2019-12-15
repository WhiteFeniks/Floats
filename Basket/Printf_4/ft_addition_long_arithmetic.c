/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addition_long_arithmetic.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:45:50 by umoff             #+#    #+#             */
/*   Updated: 2019/12/11 17:47:22 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "floats.h"

/*
** Функция сложения массива x с массивом y и точностью accuracy
*/

int	*ft_addition_long_arithmetic(int *x, int *y, int accuracy)
{
	int *result;
	int i;
	int j;

	i = accuracy - 1;
	j = accuracy - 1;
	result = ft_make_zero_str(accuracy);
	while (i != -1)
	{
		result[i] += x[j] + y[j];
		while (result[i] >= 10)
		{
			result[i - 1] = result[i] / 10;
			result[i] = result[i] % 10;
		}
		i--;
		j--;
	}
	return (result);
}
