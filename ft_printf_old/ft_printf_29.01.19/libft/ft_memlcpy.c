/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:06:17 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 18:06:20 by umoff            ###   ########.fr       */
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
