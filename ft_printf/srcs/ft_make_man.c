/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:37:58 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 16:54:09 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Вычисление дробной части. Элемент из манитисы умножаем на 2^n, где
** n < 0.
*/

void	fractional(int i, int **fract_part, int order, int **num)
{
	int *temp_1;
	int *temp_2;
	int *temp_3;

	temp_1 = *fract_part;
	temp_2 = ft_exp_long_arithmetic(i + (order * -1), 1100);
	temp_3 = ft_division_long_arithmetic(*num, temp_2, 1100, 0);
	*fract_part = ft_addition_long_arithmetic(*fract_part, temp_3, 1100);
	free(temp_1);
	free(temp_2);
	free(temp_3);
}

/*
** Вычисление целой части. Элемент из манитисы умножаем на 2^n, где
** n >= 0.
*/

void	integer(int i, int **integer_part, int order, int **num)
{
	int *temp_1;
	int *temp_2;

	temp_1 = *integer_part;
	temp_2 = ft_exp_long_arithmetic((order + (i * -1)), 1100);
	*integer_part = ft_addition_long_arithmetic(*integer_part, temp_2, 1100);
	free(temp_1);
	free(temp_2);
	free(*num);
}

/*
** Идём по мантиссе. Если эффективный порядок >= 0,
** то собираем целую часть. Если эффективный порядок < 0,
** то собираем дробную часть.
*/

int		ft_make_man(int man[], int order, t_data *new)
{
	int i;
	int *fract_part;
	int *integer_part;
	int *num;

	i = 63;
	fract_part = ft_make_zero_str(1100);
	integer_part = ft_make_zero_str(1100);
	while (i-- == 0 && (man[63] == 0))
		man[i] = '\0';
	i = -1;
	while (++i <= 63)
		if (man[i] != 0)
		{
			num = ft_make_zero_str(1100);
			num[1099] = 1;
			if ((order + (i * -1)) >= 0)
				integer(i, &integer_part, order, &num);
			else
				fractional(i, &fract_part, order, &num);
		}
	return (print_before_dot(integer_part, fract_part, new));
}
