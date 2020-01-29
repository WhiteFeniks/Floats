/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:32:37 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 23:59:37 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 5. Функция подсчитывает длину матиссы
*/

int		ft_count_mantissa(t_floats **new)
{
	int i;

	i = 63;
	while ((*new)->mantissa[i] == 0)
		i--;
	return (i);
}

/*
** 4. Функция создает строку из двух int-вых массивов
** (*new)->i = i, (*new)->j = j
*/

char	*ft_make_str(t_floats **new, int *integer_part, int *fractional_part)
{
	char	*x;

	(*new)->i = 0;
	(*new)->j = 0;
	x = ft_make_zero_char(1100);
	while (integer_part[(*new)->i] == 0 && (*new)->i < 1100)
		(*new)->i++;
	if ((*new)->i == 1100)
	{
		(*new)->j++;
		x[0] = 48;
	}
	while ((*new)->i < 1100)
		x[(*new)->j++] = integer_part[(*new)->i++] + 48;
	x[(*new)->j] = '.';
	while (fractional_part[(*new)->i] == 0 && (*new)->i >= 0)
		(*new)->i--;
	if ((*new)->i == -1)
		(*new)->i++;
	while ((*new)->i >= 0)
	{
		x[(*new)->i + (*new)->j + 1] = fractional_part[(*new)->i] + 48;
		(*new)->i--;
	}
	return (x);
}

/*
** 3. Функция собирает дробную часть (правее точки) из порядка, мантиссы
** и эффективного порядка
*/

int		*make_fractional(t_floats **new, int *x, int i)
{
	int *temp;
	int *one_arr;
	int *res;

	temp = ft_make_zero_str(1100);
	res = ft_make_zero_str(1100);
	one_arr = ft_make_zero_str(1100);
	one_arr[1099] = 1;
	if ((*new)->mantissa[i] == 1)
	{
		ft_free_new(&temp, ft_exp_long_arithmetic(ft_abs((*new)->ef_order)));
		ft_free_new(&res, ft_division_long_arithmetic(one_arr, temp, 1100, 0));
	}
	else
		free(one_arr);
	ft_free_new(&x, ft_addition_long_arithmetic(x, res, 1100));
	(*new)->ef_order--;
	free(temp);
	free(res);
	return (x);
}

/*
** 2. Функция собирает целую часть (правее точки) из порядка, мантиссы
** и эффективного порядка
*/

int		*make_integer(t_floats **new, int *x, int i)
{
	int *temp;

	temp = ft_make_zero_str(1100);
	if ((*new)->mantissa[i] == 1)
		ft_free_new(&temp, ft_exp_long_arithmetic((*new)->ef_order));
	x = ft_addition_long_arithmetic(x, temp, 1100);
	(*new)->ef_order--;
	free(temp);
	return (x);
}

/*
** 1. Функция собирает число изходя из мантиссы и порядка + эффективного порядка
** и возвращает строку result
*/

char	*my_number(t_floats **new)
{
	char	*result;
	int		*integer_part;
	int		*fractional_part;
	int		*temp1;

	(*new)->i = 0;
	integer_part = ft_make_zero_str(1100);
	fractional_part = ft_make_zero_str(1100);
	result = ft_make_zero_char(1100);
	while ((*new)->i <= ft_count_mantissa(new))
	{
		if ((*new)->ef_order >= 0)
		{
			temp1 = integer_part;
			integer_part = make_integer(new, integer_part, (*new)->i);
			free(temp1);
		}
		else
			fractional_part = make_fractional(new, fractional_part, (*new)->i);
		(*new)->i++;
	}
	ft_sps_polina(&integer_part, &fractional_part, (*new)->accuracy, (*new)->i);
	ft_free_result(&result, ft_make_str(new, integer_part, fractional_part));
	ft_free_array(integer_part, fractional_part);
	return (result);
}
