/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:47:10 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/26 18:13:56 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** вспомогательная ф-ия к ft_get_length,
** в этой функции производится исключение и запись в структуру
*/

void	ft_l_or_h(int l, int h, int big_l, t_data *new)
{
	if (big_l != 0)
		new->length = 5;
	else if (l > 0 && h == 0)
	{
		l %= 2;
		if (l == 0)
			new->length = 2;
		else
			new->length = 1;
	}
	else if (h > 0 && l == 0)
	{
		h %= 2;
		if (h == 0)
			new->length = 4;
		else
			new->length = 3;
	}
	else if (h != 0 && l != 0)
		new->length = 2;
}

/*
** ф-ия которая определяет длину
*/

void	ft_get_length(t_data *new)
{
	int l;
	int h;
	int big_l;

	l = 0;
	h = 0;
	big_l = 0;
	while (new->bs.str[new->it.i] == 'l' || new->bs.str[new->it.i] == 'L'
			|| new->bs.str[new->it.i] == 'h')
	{
		if (new->bs.str[new->it.i] == 'l')
			l++;
		else if (new->bs.str[new->it.i] == 'h')
			h++;
		else if (new->bs.str[new->it.i] == 'L')
			big_l++;
		new->it.i++;
	}
	ft_l_or_h(l, h, big_l, new);
	new->it.i--;
}

/*
** ф-ия которая определяет и записывает
** в структуру(ширина и точнось) числа
*/

int		ft_get_number(t_data *new)
{
	int	result;

	result = 0;
	if (new->bs.str[new->it.i] == '.')
	{
		new->dot = 1;
		new->it.i++;
	}
	if (new->bs.str[new->it.i] == '*')
	{
		result = va_arg(new->bs.arg, int);
		new->w = 1;
	}
	while (ft_isdigit(new->bs.str[new->it.i]) && result < 2147483647)
	{
		result = result * 10 + (new->bs.str[new->it.i] - '0');
		new->it.i++;
	}
	new->it.i--;
	return (result);
}

/*
** ф-ия которая определяет флаги
*/

void	ft_flags(t_data *new)
{
	if (new->bs.str[new->it.i] == '-')
		new->fl.minus = 1;
	else if (new->bs.str[new->it.i] == '+')
		new->fl.plus = 1;
	else if (new->bs.str[new->it.i] == ' ')
		new->fl.space = 1;
	else if (new->bs.str[new->it.i] == '#')
		new->fl.sharp = 1;
	else if (new->bs.str[new->it.i] == '0')
		new->fl.zero = 1;
}

/*
** ф-ия парсинга строки
** и запоминание данных в лист
*/

int		ft_parcing(t_data *new)
{
	while (new->bs.str[new->it.i] != '\0' &&
			new->type == '0' && new->percent < 2)
	{
		if (new->bs.str[new->it.i] == '%')
			new->percent++;
		else if (new->width == 0 && new->dot == 0 && new->length == 0 &&
				ft_memchr("-+ #0", new->bs.str[new->it.i], 5))
			ft_flags(new);
		else if ((new->width == 0 && new->dot == 0 && new->length == 0 &&
				new->w == 0 && (new->bs.str[new->it.i] == '*' ||
					ft_isdigit(new->bs.str[new->it.i]))) ||
						(ft_isdigit(new->bs.str[new->it.i]) && new->dot == 0))
			new->width = ft_get_number(new);
		else if (new->dot == 0 && new->bs.str[new->it.i] == '.')
			new->prec = ft_get_number(new);
		else if (new->length == 0 && new->type == '0' &&
				ft_memchr("Llh", new->bs.str[new->it.i], 3))
			ft_get_length(new);
		else if (new->type == '0' &&
				ft_memchr("diouxXcspfD", new->bs.str[new->it.i], 11))
			new->type = new->bs.str[new->it.i];
		new->it.i++;
	}
	return (new->it.i);
}
