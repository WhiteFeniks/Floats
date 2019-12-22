/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:45:13 by doberyn           #+#    #+#             */
/*   Updated: 2019/11/06 18:11:14 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ft_leveling - функция которая печатает определенный символ (c),
** определенное колличество раз (count)
** norme  ✓
** fixed  ✓
*/

void		ft_leveling(int count, char c, t_data *new)
{
	while (count > 0)
	{
		ft_putchar_c(c, new);
		count--;
	}
}

/*
** ft_precision - функция которая обрабатывает точность.
** norme	✓
** fixed	✓
*/

void		ft_precision(char sign, int len, t_data *new)
{
	if (sign == '#' && new->fl.sharp != 0)
	{
		ft_putstr_c("0x", new);
		ft_leveling(new->prec - 2, '0', new);
		new->fl.sharp = 0;
	}
	else if (sign == '#' && new->fl.sharp == 0)
	{
		ft_putstr_c("0x", new);
		ft_leveling(new->prec - 2, '0', new);
		new->fl.sharp = 0;
	}
	else if (sign == 'z')
	{
		ft_leveling(new->prec - len, '0', new);
		new->fl.sharp = 0;
	}
	else if (sign == '+' && new->fl.plus == 0)
		ft_leveling(new->prec - len, '0', new);
	else if ((new->fl.plus != 0 && sign == '+') || sign == '-')
		ft_leveling(new->prec - len + 1, '0', new);
}

char		ft_width_help(char sign, t_data *new)
{
	ft_putchar_c('-', new);
	sign = '.';
	return (sign);
}

/*
** ft_width - функция которая обрабатывает ширину.
** norme	✓
** fixed	✓
*/

char		ft_width(char sign, int len, t_data *new)
{
	char	c;

	c = (new->fl.zero != 0) ? '0' : ' ';
	if (new->fl.space == 1 && (new->width >= len || new->fl.minus == 0))
		ft_putchar_space(' ', new);
	if (new->fl.zero != 0 && sign == '-')
		sign = ft_width_help(sign, new);
	else if (new->fl.zero != 0 && sign == '+' && new->fl.plus != 0)
		ft_putchar_c('+', new);
	if (new->fl.space == 2 && (new->dot == 0 || new->prec < len))
		ft_leveling(new->width - len - 1, c, new);
	else if (new->fl.space == 2 && new->dot != 0)
		ft_leveling(new->width - 1 - new->prec, c, new);
	else if ((new->prec < len || new->prec == 0) && new->fl.space == 0)
		ft_leveling(new->width - len, c, new);
	else if ((new->prec <= len || new->prec == 0) && new->fl.space == 0
			&& (new->type == 'i' || new->type == 'u'))
		ft_leveling(new->width - len, c, new);
	else if (new->prec > len && (new->fl.plus == 0 && sign != '-'))
		ft_leveling(new->width - new->prec, c, new);
	else if (new->prec >= len && (new->fl.plus != 0 || sign == '-'))
		ft_leveling(new->width - new->prec - 1, c, new);
	else if (new->fl.space != 2 && new->dot == 0)
		ft_leveling(new->width - len, c, new);
	return (sign);
}
