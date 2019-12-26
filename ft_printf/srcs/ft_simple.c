/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:21:16 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/26 15:21:20 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ф-ия которая обрабатывает тип %с
*/

void			ft_print_c(t_data *new)
{
	char		c;
	char		s;

	c = (char)va_arg(new->bs.arg, int);
	s = (new->fl.zero == 0) ? ' ' : '0';
	ft_mutual_exclusion(new, 1, 'c');
	if (new->width != 0 && new->fl.minus == 0)
		ft_leveling((new->width - 1), s, new);
	ft_putchar_c(c, new);
	if (new->fl.minus != 0)
		ft_leveling((new->width - 1), s, new);
}

/*
** ф-ия которая обрабатывает тип %s
*/

void			ft_print_s(t_data *new)
{
	char		*str;
	int			len;
	char		s;

	s = (new->fl.zero == 0) ? ' ' : '0';
	str = va_arg(new->bs.arg, char *);
	str = (str == NULL) ? "(null)" : str;
	len = ft_strlen(str);
	ft_mutual_exclusion(new, 1, 's');
	new->prec = (new->prec > len) ? len : new->prec;
	if (new->dot != 0 && new->prec == 0)
		len = 0;
	if (new->prec > 0)
		len = new->prec;
	if (new->width != 0 && new->fl.minus == 0)
		ft_leveling((new->width - len), s, new);
	if (new->dot == 0 && new->prec == 0)
		ft_putstr_c(str, new);
	else
		ft_putstr_precision(str, new->prec, new);
	if (new->fl.minus != 0)
		ft_leveling((new->width - len), ' ', new);
}

/*
** ф-ия которая обрабатывает тип %p
*/

void			ft_print_p(t_data *new)
{
	long long	data;
	char		*str;
	int			g;
	int			len;

	data = (long long)va_arg(new->bs.arg, void *);
	str = ft_itoa_base_sig(data, 16);
	len = (int)ft_strlen(str) + 2;
	new->prec = (new->prec <= len - 2) ? 0 : new->prec;
	g = (new->prec == 0) ? len : new->prec + 2;
	if (new->width > g && new->fl.minus == 0)
		ft_leveling((new->width - g), ' ', new);
	ft_putstr_c("0x", new);
	if (new->dot != 0 && new->prec == 0 && data == 0)
		return ;
	if (new->prec >= len - 2)
		ft_leveling((new->prec - (len - 2)), '0', new);
	ft_putstr_c(str, new);
	if (new->width > g && new->fl.minus != 0)
		ft_leveling((new->width - g), ' ', new);
	free(str);
}

/*
** ф-ия которая обрабатывает %%
*/

void			ft_print_percent(t_data *new)
{
	char		c;

	c = (new->fl.zero == 0) ? ' ' : '0';
	if (new->width != 0 && new->fl.minus == 0)
		ft_leveling(new->width - 1, c, new);
	ft_putchar_c('%', new);
	if (new->width != 0 && new->fl.minus != 0)
		ft_leveling(new->width - 1, ' ', new);
}
