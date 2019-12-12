///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_lib2.c                                          :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2019/12/06 13:54:28 by vaisha            #+#    #+#             */
///*   Updated: 2019/12/12 14:58:27 by vaisha           ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "ft_printf.h"
//
//void	ft_putchar(char c)
//{
//	write(1, &c, 1);
//}
//
//char	*ft_strjoin(char *s1, char *s2)
//{
//	char	*a;
//
//	a = NULL;
//	if (s1 && s2)
//	{
//		if ((ft_strlen(s1) + ft_strlen(s2)) < ft_strlen(s1)
//			|| ft_strlen(s1) + ft_strlen(s2) < ft_strlen(s2))
//			return (NULL);
//		a = (char *)malloc(sizeof(char)
//			* (ft_strlen(s1) + ft_strlen(s2) + 1));
//		if (!a)
//			return (NULL);
//		ft_strcpy(a, s1);
//		ft_strcat(a, s2);
//	}
//	return (a);
//}
//
//int		ft_strlen(const char *str)
//{
//	int	i;
//
//	i = 0;
//	while (str[i] != '\0' && i + 1 != 0)
//		i++;
//	return (i);
//}
//
//char	*ft_strnew(size_t size)
//{
//	char	*a;
//
//	if (size + 1 < size)
//		return (NULL);
//	if ((a = (char *)malloc(sizeof(char) * (size + 1))))
//	{
//		ft_memset(a, (int)'\0', size + 1);
//		return (a);
//	}
//	return (NULL);
//}
//
//int		ft_isalpha(int c)
//{
//	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//		return (1);
//	else
//		return (0);
//}
