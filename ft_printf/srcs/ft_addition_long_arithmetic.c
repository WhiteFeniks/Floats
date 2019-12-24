/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addition_long_arithmetic.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:12:14 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 18:03:53 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Функция сложения одного числа а с другим b (длинная арфиметика)
*/

int	*ft_addition_long_arithmetic(int *a, int *b, int acc)
{
	int *rez;
	int i;
	int j;

	i = acc - 1;
	j = acc - 1;
	rez = ft_make_zero_str(acc);
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
