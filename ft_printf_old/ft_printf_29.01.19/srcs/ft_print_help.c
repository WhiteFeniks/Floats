/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:21:18 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 17:50:43 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Функция печати числа
*/

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

/*
** Функция печати точки
*/

void	ft_putchar_dot(t_data *new)
{
	ft_putchar_c('.', new);
	new->it.save++;
}

/*
** Функция печати.
** (см. ft_leveling - функция которая печатает определенный символ)
** определенное колличество раз (count)
*/

void	ft_print_after(t_data *new, int len)
{
	if (new->width > len)
		ft_leveling(new->width - len, ' ', new);
}

/*
** Вспомогательная функция печати до точки и free
*/

void	print_before_dot_addit(int *integer_part, int *fract_part,
		t_data *new, int j)
{
	if (new->fl.minus != 0)
		ft_print_after(new, new->it.save + j + new->prec);
	free(fract_part);
	free(integer_part);
}

/*
** Дополнительная функция подсчета длины, чтобы можно было
** вывести определенной ширины
*/

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
