/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:15:43 by bglover           #+#    #+#             */
/*   Updated: 2019/11/06 18:26:05 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_c(int n, t_data *new)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_c(n / 10, new);
		}
		ft_putchar_c((n % 10) + '0', new);
	}
}

void	ft_print_after(t_data *new, int len)
{
	if (new->width > len)
		ft_leveling(new->width - len, ' ', new);
}

void	ft_putchar_1(t_data *new)
{
	ft_putchar_c('.', new);
	new->it.save++;
}

/*
** Вспомогательная функция печати после точки и free
*/

void	print_before_dot_help(int *rez_celoe, t_data *new, int *rez, int j)
{
	if (new->fl.minus != 0)
		ft_print_after(new, new->it.save + j + new->prec);
	free(rez);
	free(rez_celoe);
}

int		ft_get_size_f(t_data *new, int j)
{
	int count;

	count = 0;
	count += j + new->prec;
	if (new->fl.plus != 0)
		count += 1;
	if (new->prec != 0)
		count += 1;
	if (new->prec == 0 && new->fl.sharp != 0)
		count += 1;
	if (new->fl.space != 0)
		count += 1;
	return (count);
}
