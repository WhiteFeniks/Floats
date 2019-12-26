/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutual_exclusion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:46:53 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/26 16:46:55 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** взаимоисключение точности
*/

void	ft_mutual_exclusion_prec(int len, t_data *new)
{
	if (new->prec <= len)
		new->prec = 0;
}

/*
** взаимоисключение ширины
*/

void	ft_mutual_exclusion_width(int len, t_data *new)
{
	if (new->width <= len)
		new->width = 0;
	else if (new->prec != 0)
	{
		if (new->width <= new->prec + 2 && new->fl.sharp != 0)
			new->width = 0;
		else if (new->width <= new->prec && new->fl.sharp == 0)
			new->width = 0;
	}
}

void	ft_mutual_exclusion_help(t_data *new, long long data, char c)
{
	if (new->fl.plus != 0 && data < 0)
		new->fl.plus = 0;
	if (c == 'f' && new->fl.minus != 0 && new->fl.zero != 0)
		new->fl.zero = 0;
}

/*
** ф-ия которая взаимоисключает флаги
*/

void	ft_mutual_exclusion(t_data *new, long long data, char c)
{
	if (new->fl.zero != 0 && (new->dot != 0 || new->fl.minus != 0) && c != 'f')
		new->fl.zero = 0;
	if (new->fl.space != 0 && (new->fl.plus != 0 || data < 0))
		new->fl.space = 0;
	if (new->fl.sharp != 0 && data == 0 && c == 'x')
		new->fl.sharp = 0;
	if (new->type == 'u' && new->fl.space != 0)
		new->fl.space = 0;
	if (new->type == 'u' && new->fl.plus != 0)
		new->fl.plus = 0;
	if (new->type == 'd' && new->fl.zero != 0 && new->width <=
			(int)(ft_intlen(data) + 1) && new->fl.plus != 0)
		new->fl.zero = 0;
	if (new->width < 0)
	{
		new->fl.minus = 1;
		new->width *= -1;
	}
	if (new->prec < 0)
	{
		new->prec = new->width;
		new->dot = 0;
	}
	ft_mutual_exclusion_help(new, data, c);
}
