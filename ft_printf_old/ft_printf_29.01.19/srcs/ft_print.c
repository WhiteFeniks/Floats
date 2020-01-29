/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:12:32 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 17:26:00 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Вывод на печать чисел после точки
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
** Округление целой и дробной части числа
*/

void	round_res(int *integer_part, int *fract_part, t_data *new)
{
	int i;

	i = new->prec;
	if (new->prec == 0)
		if (fract_part[0] >= 5)
			integer_part[1099]++;
	if (fract_part[i] != 0 && fract_part[i] >= 5)
		fract_part[i - 1] += 1;
	if (fract_part[i - 1] == 10)
		while (fract_part[--i] == 10)
		{
			fract_part[i - 1] += fract_part[i] / 10;
			fract_part[i] = fract_part[i] % 10;
			if (i == 0)
			{
				i = 1099;
				integer_part[i] += 1;
				while (integer_part[i] == 10)
				{
					integer_part[i - 1] += integer_part[i] / 10;
					integer_part[i] = integer_part[i] % 10;
				}
			}
		}
}

/*
** Функция для печати различных флагов
*/

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
		ft_putchar_dot(new);
}

/*
** Дополнительная функция для печати числа до точки
** (см. ft_mutual_exclusion - функция которая взаимоисключает флаги)
*/

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
** Функция округления и вывода на печать числа до точки
** при этом учитывая флаги
*/

int		print_before_dot(int *integer_part, int *fract_part, t_data *new)
{
	int i;
	int j;

	round_res(integer_part, fract_part, new);
	i = 0;
	while (integer_part[i] == 0 && i + 1 != 1100)
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
		ft_putnbr_c(integer_part[i++], new);
	if (new->prec > 0 || (new->fl.sharp != 0 && new->prec == 0))
		ft_putchar_flag(new, '.');
	i = print_after_dot(fract_part, new, j);
	print_before_dot_addit(integer_part, fract_part, new, j);
	return (i);
}
