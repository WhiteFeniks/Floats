/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:41:20 by bglover           #+#    #+#             */
/*   Updated: 2019/11/06 17:51:13 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	 Вычисление порядка
*/

int		make_por(int por[])
{
	int		i;
	int		j;
	int		k;
	short	digit;

	i = 14;
	j = -1;
	k = 0;
	digit = 0;
	while (i >= 0)
	{
		if (por[i] == 0 || (i == 15 && por[i] == 1))
			j++;
		else if (i != 15 && por[i] == 1)
		{
			j++;
			while (k++ < j)
				por[i] *= 2;
			k = 0;
		}
		digit += por[i--];
	}
	return (digit - 16383);
}

/*
** Проверка на бесконечность
*/

int		ft_check_inf(int por[], int man[])
{
	int i;
	int j;

	i = 0;
	j = 63;
	while (por[i] == 1)
		i++;
	while (man[j] == 0)
		j--;
	if (i == 15 && j == 0)
		return (1);
	return (0);
}

/*
** Распределение по маскам
*/

int		find_numb(char bin_numb[], t_data *new)
{
	int	i;
	int	j;
	int	por[15];
	int	man[64];

	i = 0;
	j = 0;
	while (i < 80)
	{
		if (i == 0)
			new->sign = bin_numb[i];
		else if (i < 16)
			por[j++] = bin_numb[i];
		else
		{
			if (i == 16)
				j = 0;
			man[j++] = bin_numb[i];
		}
		i++;
	}
	if (ft_check_inf(por, man))
		return (ft_print_inf(new));
	return (make_man(man, make_por(por), new));
}

/*
** Запись битов в массив
*/

int		print_bits(size_t const size, void const *const ptr,
			t_data *new, int bn)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	int				j;
	char			bin_numb[80];

	b = (unsigned char*)ptr;
	i = size - 1;
	j = 7;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			bin_numb[bn++] = byte;
			j--;
		}
		i--;
	}
	return (find_numb(bin_numb, new));
}

/*
** Начало алгоритма
*/

int		ft_print_float(t_data *new)
{
	t_un		un_1;
	long double db;
	int			i;

	if (new->dot == 0)
		new->prec = -1;
	if (new->length == 5)
		db = (long double)va_arg(new->bs.arg, long double);
	else
		db = (long double)va_arg(new->bs.arg, double);
	un_1.i = db;
	if (db != db)
		return (ft_print_nan(new));
	if (new->prec == -1)
		new->prec = 6;
	if (new->fl.sharp && new->prec == 0)
	{
		i = print_bits(10, &un_1.i, new, 0);
		return (i + 1);
	}
	return (print_bits(10, &un_1.i, new, 0));
}
