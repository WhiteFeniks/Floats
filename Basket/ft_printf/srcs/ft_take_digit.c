/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:35:42 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/10 14:04:05 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_take_digit(const char *format, int i, t_data *list)
{
	int result;

	result = 0;
	while (ft_isdigit(format[i]) && result < 2147483647)
		result = result * 10 + (format[i++] - '0');
	if (list->point == '0')
		list->width = result;
	else if (list->point == '.')
		list->accuracy = result;
	i--;
	return (i);
}

int	ft_l(const char *format, int i, t_data *list)
{
	if (format[i] == 'l' && format[i + 1] == 'l')
	{
		list->length = 4;
		i++;
	}
	else if (format[i] == 'l' && format[i + 1] != 'l')
		list->length = 2;
	return (i);
}

int	ft_h(const char *format, int i, t_data *list)
{
	if (format[i] == 'h' && format[i + 1] == 'h')
	{
		list->length = 5;
		i++;
	}
	else if (format[i] == 'h' && format[i + 1] != 'h')
		list->length = 3;
	return (i);
}
