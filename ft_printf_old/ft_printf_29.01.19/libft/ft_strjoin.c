/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:06:42 by umoff             #+#    #+#             */
/*   Updated: 2019/12/24 18:06:44 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[i] != '\0')
		str[c++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[c++] = s2[i++];
	str[c] = '\0';
	return ((char *)str);
}
