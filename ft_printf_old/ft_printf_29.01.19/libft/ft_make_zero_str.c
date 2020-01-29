/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_zero_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:29:48 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 15:29:52 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*ft_make_zero_str(int size)
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
