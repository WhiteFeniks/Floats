/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:50:32 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/06 13:52:58 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//int		ft_isdigit(int c)
//{
//	if (c >= '0' && c <= '9')
//		return (1);
//	else
//		return (0);
//}
//
//void	*ft_memset(void *destination, int c, size_t n)
//{
//	char	*str;
//	int		i;
//
//	str = destination;
//	i = 0;
//	while (n != 0)
//	{
//		str[i] = c;
//		n--;
//		i++;
//	}
//	return (str);
//}
//
//char	*ft_strcat(char *destination, const char *append)
//{
//	int		i;
//	int		j;
//
//	i = 0;
//	j = 0;
//	while (destination[i] != '\0')
//		i++;
//	while (append[j] != '\0')
//	{
//		destination[i] = append[j];
//		i++;
//		j++;
//	}
//	destination[i] = '\0';
//	return (destination);
//}
//
////char	*ft_strcpy(char *str1, char *str2)
////{
////	int		i;
////
////	i = 0;
////	while (str2[i] != '\0')
////	{
////		str1[i] = str2[i];
////		i++;
////	}
////	str1[i] = '\0';
////	return (str1);
////}
//
////char	*ft_strdup(const char *str)
////{
////	char	*a;
////	int		i;
////
////	i = 0;
////	a = NULL;
////	while (str[i] != '\0')
////		i++;
////	a = (char *)malloc(i + 1);
////	i = 0;
////	if (a)
////	{
////		while (str[i] != '\0')
////		{
////			a[i] = str[i];
////			i++;
////		}
////		a[i] = '\0';
////		return (a);
////	}
////	return (NULL);
////}
