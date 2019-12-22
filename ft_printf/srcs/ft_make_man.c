/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:25:29 by bglover           #+#    #+#             */
/*   Updated: 2019/12/22 05:26:01 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Вычисление дробной части
*/

void	right(int i, int **rez, int por, int **num)
{
	int *temp_1;
	int *temp_2;
	int *temp_3;

	temp_1 = *rez;
	temp_2 = ft_exp_long_arithmetic(i + (por * -1), 1100);
	temp_3 = ft_division_long_arithmetic(*num, temp_2, 1100, 0);
	*rez = ft_addition_long_arithmetic(*rez, temp_3, 1100);
	free(temp_1);
	free(temp_2);
	free(temp_3);
}

/*
** Вычисление целой части
*/

void	left(int i, int **rez_celoe, int por, int **num)
{
	int *temp_1;
	int *temp_2;

	temp_1 = *rez_celoe;
	temp_2 = ft_exp_long_arithmetic((por + (i * -1)), 1100);
	*rez_celoe = ft_addition_long_arithmetic(*rez_celoe, temp_2, 1100);
	free(temp_1);
	free(temp_2);
	free(*num);
}

/*
**	 Вычисление мантиссы
*/

int		make_man(int man[], int por, t_data *new)
{
	int i;
	int *rez;
	int *rez_celoe;
	int *num;

	i = 63;
	rez = ft_intstr(1100);
	rez_celoe = ft_intstr(1100);
	while (i-- == 0 && (man[63] == 0))
		man[i] = '\0';
	i = -1;
	while (++i <= 63)
		if (man[i] != 0)
		{
			num = ft_intstr(1100);
			num[1099] = 1;
			if ((por + (i * -1)) >= 0)
				left(i, &rez_celoe, por, &num);
			else
				right(i, &rez, por, &num);
		}
	return (print_before_dot(rez_celoe, new, rez));
}
