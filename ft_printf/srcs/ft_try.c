/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:42:26 by bglover           #+#    #+#             */
/*   Updated: 2019/12/22 05:23:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Вспомогательные функции мантиссы
*/

int	*ft_first_try(int **temp, int **div, int acc)
{
	int *temp_1;

	temp_1 = *temp;
	*temp = ft_addition_long_arithmetic(*temp, *div, acc);
	free(temp_1);
	return (*temp);
}

int	*ft_second_try(int **temp, int **div, int acc)
{
	int *temp_1;

	temp_1 = *temp;
	*temp = ft_difference_long_arithmetic(*temp, *div, acc);
	free(temp_1);
	return (*temp);
}

int	*ft_third_try(int **num, int **temp, int acc)
{
	int *temp_1;

	temp_1 = *num;
	*num = ft_difference_long_arithmetic(*num, *temp, acc);
	free(temp_1);
	return (*num);
}

/*
** Вспомогательная функция деления
*/

int	*ft_trying_four(int **num, int *rez)
{
	free(*num);
	return (rez);
}
