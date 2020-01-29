/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:00:38 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 18:00:41 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Вспомогательные функции деления для длинной арифметики
** чтобы уместить в 25 строк
*/

int	*ft_division_add_1(int **temp, int **div, int acc)
{
	int *temp_1;

	temp_1 = *temp;
	*temp = ft_addition_long_arithmetic(*temp, *div, acc);
	free(temp_1);
	return (*temp);
}

int	*ft_division_add_2(int **temp, int **div, int acc)
{
	int *temp_1;

	temp_1 = *temp;
	*temp = ft_difference_long_arithmetic(*temp, *div, acc);
	free(temp_1);
	return (*temp);
}

int	*ft_division_add_3(int **num, int **temp, int acc)
{
	int *temp_1;

	temp_1 = *num;
	*num = ft_difference_long_arithmetic(*num, *temp, acc);
	free(temp_1);
	return (*num);
}

int	*ft_division_free(int **num, int *rez)
{
	free(*num);
	return (rez);
}
