/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:41:34 by doberyn           #+#    #+#             */
/*   Updated: 2019/11/06 18:35:46 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ft_structure_cleaning - зачистка структуры для
** повторного применения.
** norme  ✓
** fixed  ✓
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
** ft_determination - функция которая определяет в какую
** функцию отправить струкруту.
** norme	✓
** fixed	✓
*/

void		ft_determination(t_data *new)
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
		ft_print_float(new);
}

/*
** ft_start - функция которая инициализирует переменные.
** norme	✓
** fixed	✓
*/

void		ft_start(const char *format, t_data *new)
{
	new->it.i = 0;
	new->it.count = 0;
	new->bs.str = format;
}

/*
** ft_vprintf - функция которая запускает весь процесс
** norme	✓
** fixed	✓
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
			new->it.g = ft_structuring(new);
			ft_determination(new);
		}
		new->it.i = (new->it.g != 0) ? new->it.g : new->it.i + 1;
	}
	return (new->it.count);
}

/*
** ft_printf - главная функция которая передеает
** начальные значения и активирует библеотеку stdarg.
** norme	✓
** fixed	✓
*/

int			ft_printf(const char *format, ...)
{
	t_data	new;
	int		done;

	va_start(new.bs.arg, format);
	done = ft_vprintf(format, &new);
	va_end(new.bs.arg);
	return (done);
}
