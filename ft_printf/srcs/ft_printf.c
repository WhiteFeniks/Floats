/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:00:50 by umoff             #+#    #+#             */
/*   Updated: 2019/12/26 18:14:15 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** зачистка структуры для
** повторного применения
*/

void		ft_structure_cleaning(t_data *new)
{
	new->fl.zero = 0;
	new->fl.sharp = 0;
	new->fl.space = 0;
	new->fl.plus = 0;
	new->fl.minus = 0;
	new->it.g = 0;
	new->percent = 0;
	new->width = 0;
	new->prec = 0;
	new->dot = 0;
	new->length = 0;
	new->type = '0';
	new->w = 0;
}

/*
** ф-ия которая определяет в какую
** функцию отправить струкруту
*/

void		ft_allocation(t_data *new)
{
	if (new->type == 'c')
		ft_print_c(new);
	else if (new->type == 's')
		ft_print_s(new);
	else if (new->type == 'p')
		ft_print_p(new);
	else if (new->percent == 2)
		ft_print_percent(new);
	else if (new->type == 'd' || new->type == 'i' || new->type == 'D')
		ft_print_dec(new);
	else if (new->type == 'u')
		ft_print_u(new);
	else if (new->type == 'o')
		ft_print_o(new);
	else if (new->type == 'x' || new->type == 'X')
		ft_print_x(new);
	else if (new->type == 'f')
		ft_floats(new);
}

/*
** ф-ия которая инициализирует переменные
*/

void		ft_start(const char *format, t_data *new)
{
	new->it.i = 0;
	new->it.count = 0;
	new->bs.str = format;
}

/*
** ф-ия которая запускает весь процесс
*/

int			ft_vprintf(const char *format, t_data *new)
{
	ft_start(format, new);
	while (new->bs.str[new->it.i] != '\0')
	{
		new->it.g = 0;
		if (new->bs.str[new->it.i] != '%')
			ft_putchar_c(new->bs.str[new->it.i], new);
		else
		{
			ft_structure_cleaning(new);
			new->it.g = ft_parcing(new);
			ft_allocation(new);
		}
		new->it.i = (new->it.g != 0) ? new->it.g : new->it.i + 1;
	}
	return (new->it.count);
}

/*
** главная ф-ия которая передает
** начальные значения и активирует stdarg
*/

int			ft_printf(const char *format, ...)
{
	t_data	new;
	int		ret;

	va_start(new.bs.arg, format);
	ret = ft_vprintf(format, &new);
	va_end(new.bs.arg);
	return (ret);
}
