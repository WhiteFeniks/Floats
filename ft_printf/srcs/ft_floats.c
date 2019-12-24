/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:12:41 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 15:38:40 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Функция перевода порядка из 2-ой системы в десятичную и вычитание
** числа 16383 (011 1111 1111 1111), чтобы вычислить эффективный порядок
*/

int		make_order(int order[])
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
		if (order[i] == 0 || (i == 15 && order[i] == 1))
			j++;
		else if (i != 15 && order[i] == 1)
		{
			j++;
			while (k++ < j)
				order[i] *= 2;
			k = 0;
		}
		digit += order[i--];
	}
	return (digit - 16383);
}

/*
** Проверка на inf:
** sign = либо 0, либо 1 бит, указывающий полож./отриц. бесконечность.
** exponent = все 1 бит.
** mantissa = все 0 бит.
*/

int		check_inf(int order[], int man[])
{
	int i;
	int j;

	i = 0;
	j = 63;
	while (order[i] == 1)
		i++;
	while (man[j] == 0)
		j--;
	if (i == 15 && j == 0)
		return (1);
	return (0);
}

/*
** Функция разбивки числа на мантису, порядок и знак и проверки на inf
*/

int		number_breakdown(char number_of_bits[], t_data *new)
{
	int	i;
	int	j;
	int	order[15];
	int	man[64];

	i = 0;
	j = 0;
	while (i < 80)
	{
		if (i == 0)
			new->sign = number_of_bits[i];
		else if (i < 16)
			order[j++] = number_of_bits[i];
		else
		{
			if (i == 16)
				j = 0;
			man[j++] = number_of_bits[i];
		}
		i++;
	}
	if (check_inf(order, man))
		return (ft_print_inf(new));
	return (ft_make_man(man, make_order(order), new));
}

/*
** Функция записи нашего числа из десятичной системы в двоичную
** number_of_bits, как это число записано в памяти компьютера
** i именно такое т.к. начинаем с 0, то чтобы пройти по всему числу нужно
** step(равно 10) - 1 раз пройти в цикле
** наше число записываем в temp
** j такое, т.к. long double 80 байт, чтобы пройти всё число надо пройти
** по 8 чисел 10 раз
** далее в цикле переписываем в массив number_of_bits поочередно выделяя
** по 1 байту (для этого смещаем на j-e количество и умножаем
** на маску 00000001) и получаем как число записано в компьютере
*/

int		write_number_in_binary(size_t const step, void const *const ptr,
			t_data *new, int bn)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	int				j;
	char			number_of_bits[80];

	b = (unsigned char*)ptr;
	i = step - 1;
	j = 7;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			number_of_bits[bn++] = byte;
			j--;
		}
		i--;
	}
	return (number_breakdown(number_of_bits, new));
}

/*
** Функция принимает число и раскидывает в зависимости
** от флага либо в long double, либо double. И запускает
** функцию записи битов в массив
*/

int		ft_floats(t_data *new)
{
	t_un		un_1;
	long double num;
	int			i;

	if (new->dot == 0)
		new->prec = -1;
	if (new->length == 5)
		num = (long double)va_arg(new->bs.arg, long double);
	else
		num = (long double)va_arg(new->bs.arg, double);
	un_1.i = num;
	if (num != num)
		return (ft_print_nan(new));
	if (new->prec == -1)
		new->prec = 6;
	if (new->fl.sharp && new->prec == 0)
	{
		i = write_number_in_binary(10, &un_1.i, new, 0);
		return (i + 1);
	}
	return (write_number_in_binary(10, &un_1.i, new, 0));
}
