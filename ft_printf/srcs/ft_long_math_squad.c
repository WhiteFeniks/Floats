/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_math_squad.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:18:46 by bglover           #+#    #+#             */
/*   Updated: 2019/10/28 17:11:19 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	*ret(int *rez, int acc)
{
	rez[acc - 1] = 1;
	return (rez);
}

int	*ft_long_math_squad(int squad, int acc)
{
	int i;
	int *rez;

	rez = ft_intstr(acc);
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
