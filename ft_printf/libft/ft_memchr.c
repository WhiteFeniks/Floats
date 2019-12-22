/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:10:53 by doberyn           #+#    #+#             */
/*   Updated: 2019/04/18 13:55:10 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;

	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
