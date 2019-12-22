/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:03:58 by doberyn           #+#    #+#             */
/*   Updated: 2019/04/18 13:50:43 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memlcpy(void *dst, const void *src, size_t n, int pos)
{
	size_t		i;
	char		*d;
	const char	*s;
	int			p;

	p = pos;
	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	while (i < n)
	{
		d[p] = s[i];
		i++;
		p++;
	}
	return ((void *)d);
}
