/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_sig.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:05:01 by doberyn           #+#    #+#             */
/*   Updated: 2019/10/23 17:05:05 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long		ft_abs(long long nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char			*ft_itoa_base_sig(long long value, int base)
{
	char		*str;
	short		size;
	char		*tab;
	long long	tmp;

	size = 0;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}
