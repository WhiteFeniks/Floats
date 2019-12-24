/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:06:23 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 18:06:26 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	counter;

	str = (char *)b;
	counter = 0;
	while (counter != len)
	{
		str[counter] = (char)c;
		counter++;
	}
	return ((void *)str);
}
