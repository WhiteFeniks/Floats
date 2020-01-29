/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nan_inf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:34:20 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 17:35:08 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Печать nan со сдвигом
** (см. ft_leveling - функция которая печатает определенный символ)
** определенное колличество раз (count)
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
** Печать inf со сдвигом и знаком
** (см. ft_leveling - функция которая печатает определенный символ)
** определенное колличество раз (count)
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
