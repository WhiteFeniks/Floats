/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nan_inf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:39:21 by bglover           #+#    #+#             */
/*   Updated: 2019/11/06 17:52:14 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Печать nan со сдвигом
*/

int		ft_print_nan(t_data *new)
{
	if (new->width > 3 && new->fl.minus == 0)
		ft_leveling(new->width - 3, ' ', new);
	ft_putstr_c("nan", new);
	if (new->width > 3 && new->fl.minus != 0)
		ft_leveling(new->width - 3, ' ', new);
	return (0);
}

/*
** Печать юесконечности со сдвигом и знаком
*/

int		ft_print_inf(t_data *new)
{
	int		c;
	char	s;

	s = (new->sign == 1) ? '-' : '+';
	c = (new->fl.plus != 0 || new->sign == 1) ? 4 : 3;
	c = (new->fl.space != 0 && new->sign == 0) ? c + 1 : c;
	if (new->fl.space != 0 && new->width < 3 && new->sign == 0)
		ft_putchar_c(' ', new);
	if (new->width > c && new->fl.minus == 0)
		ft_leveling(new->width - c, ' ', new);
	if (new->fl.plus != 0 || new->sign == 1)
		ft_putchar_c(s, new);
	ft_putstr_c("inf", new);
	if (new->width > c && new->fl.minus != 0)
		ft_leveling(new->width - c, ' ', new);
	return (0);
}
