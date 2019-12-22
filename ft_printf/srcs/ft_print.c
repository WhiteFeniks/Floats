/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:22:25 by bglover           #+#    #+#             */
/*   Updated: 2019/11/06 18:16:56 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	 Вывод на печать чисел после точки
*/

int		print_after_dot(int *rez, t_data *new, int j)
{
	int i;

	i = 0;
	if (new->prec > 1100)
	{
		while (i < 1100)
			ft_putnbr_c(rez[i++], new);
		while (i++ < new->prec)
			ft_putnbr_c(0, new);
	}
	else
		while (i < new->prec)
			ft_putnbr_c(rez[i++], new);
	return (j + new->prec + 1);
}

/*
** Округление вывода
*/

void	round_rez(int *rez_celoe, int *rez, t_data *new)
{
	int i;

	i = new->prec;
	if (new->prec == 0)
		if (rez[0] >= 5)
			rez_celoe[1099]++;
	if (rez[i] != 0 && rez[i] >= 5)
		rez[i - 1] += 1;
	if (rez[i - 1] == 10)
		while (rez[--i] == 10)
		{
			rez[i - 1] += rez[i] / 10;
			rez[i] = rez[i] % 10;
			if (i == 0)
			{
				i = 1099;
				rez_celoe[i] += 1;
				while (rez_celoe[i] == 10)
				{
					rez_celoe[i - 1] += rez_celoe[i] / 10;
					rez_celoe[i] = rez_celoe[i] % 10;
				}
			}
		}
}

void	ft_putchar_flag(t_data *new, char c)
{
	if (c == '+')
	{
		ft_putchar_c('+', new);
		new->fl.plus = 0;
		new->it.save++;
	}
	if (c == '#')
	{
		ft_putchar_c('.', new);
		new->fl.sharp = 0;
		new->it.save++;
	}
	if (c == '-')
	{
		ft_putchar_c('-', new);
		new->sign = 0;
	}
	if (c == ' ')
	{
		ft_putchar_c(' ', new);
		new->fl.space = 0;
		new->it.save++;
	}
	if (c == '.')
		ft_putchar_1(new);
}

void	ft_print_before(t_data *new, int j)
{
	int		len;
	char	c;

	c = (new->fl.zero == 0) ? ' ' : '0';
	ft_mutual_exclusion(new, new->sign * -1, 'f');
	len = ft_get_size_f(new, j);
	if (new->fl.space != 0)
		ft_putchar_flag(new, ' ');
	if (new->sign == 1 && new->fl.zero != 0)
		ft_putchar_flag(new, '-');
	if (new->fl.plus != 0 && new->fl.zero != 0)
		ft_putchar_flag(new, '+');
	if (new->width > len)
		ft_leveling(new->width - len, c, new);
	if (new->sign == 1 && new->fl.zero == 0)
		ft_putchar_flag(new, '-');
	if (new->fl.plus != 0 && new->fl.zero == 0)
		ft_putchar_flag(new, '+');
}

/*
**	 Вывод на печать чисел до точки
*/

int		print_before_dot(int *rez_celoe, t_data *new, int *rez)
{
	int i;
	int j;

	round_rez(rez_celoe, rez, new);
	i = 0;
	while (rez_celoe[i] == 0 && i + 1 != 1100)
		i++;
	j = 1100 - i + new->sign;
	if (new->fl.minus == 0)
		ft_print_before(new, j);
	if (new->fl.minus != 0 && new->fl.space != 0 && (new->sign != 1 ||
	new->fl.plus != 0))
		ft_putchar_flag(new, ' ');
	if (new->fl.plus != 0 && new->fl.minus != 0 && new->sign == 0)
		ft_putchar_flag(new, '+');
	else if (new->fl.minus != 0 && new->sign == 1)
		ft_putchar_flag(new, '-');
	while (i < 1100)
		ft_putnbr_c(rez_celoe[i++], new);
	if (new->prec > 0 || (new->fl.sharp != 0 && new->prec == 0))
		ft_putchar_flag(new, '.');
	i = print_after_dot(rez, new, j);
	print_before_dot_help(rez_celoe, new, rez, j);
	return (i);
}
