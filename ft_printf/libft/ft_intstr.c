/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:07:26 by bglover           #+#    #+#             */
/*   Updated: 2019/09/20 18:38:34 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*ft_intstr(int size)
{
	int	*str;
	int	i;

	i = -1;
	if (!size)
		return (0);
	str = malloc(sizeof(int) * size);
	if (!str)
		return (NULL);
	while (++i < size)
		str[i] = 0;
	return (str);
}
