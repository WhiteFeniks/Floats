/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:42:26 by bglover           #+#    #+#             */
/*   Updated: 2019/10/29 19:22:25 by bglover          ###   ########.fr       */
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
	*temp = ft_long_math_summ(*temp, *div, acc);
	free(temp_1);
	return (*temp);
}

int	*ft_second_try(int **temp, int **div, int acc)
{
	int *temp_1;

	temp_1 = *temp;
	*temp = ft_long_math_substraction(*temp, *div, acc);
	free(temp_1);
	return (*temp);
}

int	*ft_third_try(int **num, int **temp, int acc)
{
	int *temp_1;

	temp_1 = *num;
	*num = ft_long_math_substraction(*num, *temp, acc);
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
