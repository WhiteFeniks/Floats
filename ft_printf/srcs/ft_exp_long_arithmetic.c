/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_long_arithmetic.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:12:33 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 18:02:06 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	*ret(int *rez, int acc)
{
	rez[acc - 1] = 1;
	return (rez);
}

/*
** Функция возведения в степень двойки (длинная арфиметика)
*/

int	*ft_exp_long_arithmetic(int squad, int acc)
{
	int i;
	int *rez;

	rez = ft_make_zero_str(acc);
	if (squad == 0)
		return (ret(rez, acc));
	rez[acc - 1] = 2;
	while (squad > 1)
	{
		i = acc - 1;
		while (i >= 0)
		{
			rez[i] *= 2;
			while (rez[i] >= 10)
			{
				rez[i - 1] = 2 * rez[i - 1] + (rez[i] / 10);
				rez[i] %= 10;
				i--;
			}
			i--;
		}
		squad--;
	}
	return (rez);
}
