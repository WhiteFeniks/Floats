/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lf_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:33:50 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 22:57:20 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 4. Функция записи нашего числа из десятичной системы в двоичную
** number_of_bits, как это число записано в памяти компьютера
** i именно такое т.к. начинаем с 0, то чтобы пройти по всему числу нужно
** step(равно 10) - 1 раз пройти в цикле
** наше число записываем в temp
** j такое, т.к. long double 80 байт, чтобы пройти всё число надо пройти
** по 8 чисел 10 раз
** далее в цикле переписываем в массив number_of_bits поочередно выделяя
** по 1 байту
** (для этого смещаем на j-e количество и умножаем на маску 00000001)
** получаем как число записано в компьютере
*/

char	*write_lf_number_in_binary(size_t const step,
	void *value, f_floats **new)
{
	int				i;
	int				j;
	int				k;
	char			number_of_bits[80];
	unsigned char	*temp;

	i = step - 1;
	k = 0;
	temp = (unsigned char *)value;
	while (i != -1)
	{
		j = (80 / step) - 1;
		while (j != -1)
		{
			number_of_bits[k++] = (temp[i] >> j) & 1;
			j--;
		}
		i--;
	}
	return (number_breakdown(number_of_bits, new));
}

/*
** 2. Функция запсивывает полученно значение в поле х, в объединении value pwd
** нужно зайти в цикл, чтобы получить число 80 (long double)
** в нашем случае size_array составляет 10, значит нужно 8 раз зайти в цикл
** в объединение в поле х записываем наше число
** sizeof - это унарный оператор, возвращающий длину в байтах переменной
** или типа, помещенных в скобки
** отправляем наше количество заходов в цикл, и адрес на наше число
*/

char	*write_lf_number(long double num, f_floats **new)
{
	int				size_array;
	union number	value;

	value.x = num;
	size_array = sizeof(value.my_array);
	return (write_lf_number_in_binary(size_array, &value.x, new));
}

/*
** 1. Основная функция ft_floats
*/

char	*ft_lf_floats(long double num, long long int accuracy)
{
	f_floats	*new;
	char		*result;
	char		*temp;
	char		*t;

	t = NULL;
	new = (f_floats*)malloc(sizeof(f_floats));
	if (num != num)
	{
		result = ft_make_zero_char(3);
		temp = result;
		free(temp);
		result[0] = 'n';
		result[1] = 'a';
		result[2] = 'n';
		return (result);
	}
	new->accuracy = accuracy;
	result = write_lf_number(num, &new);
	free(new);
	t = ft_strdup(result);
	free(result);
	if (new->sign == 1)
		result = ft_strjoin("-", t);
	else
		result = ft_strdup(t);
	free(t);
	return (result);
}
