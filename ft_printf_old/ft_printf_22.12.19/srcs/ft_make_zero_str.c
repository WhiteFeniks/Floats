/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_zero_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:58:13 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 22:58:50 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Функция создания int-овой строки размера size
*/

int	*ft_make_zero_str(int size)
{
	int *s;
	int i;

	i = 0;
	if (size == 0)
		return (0);
	if (!(s = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
