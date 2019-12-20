/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:01:54 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/12 15:30:50 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_accuracy_u(t_data *list, char *tmp)
{
	char				*ret;

	ret = NULL;
	ft_clean_counts(list);
	list->len = ft_strlen(tmp);
	if (list->accuracy >= list->len)
	{
		ret = (char*)malloc(sizeof(char) * list->accuracy + 1);
		while (list->accuracy-- > list->len)
			ret[list->i++] = '0';
		while (tmp[list->j])
			ret[list->i++] = tmp[list->j++];
		ret[list->i] = '\0';
	}
	else if (list->accuracy == 0 && list->point == '.')
	{
		ret = (char*)malloc(sizeof(char) * 1);
		ret[0] = '\0';
	}
	else
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	return (ret);
}

char					*ft_conversion_u(long long int value, int base)
{
	char				*str;
	short				size;
	char				*tab;
	unsigned long long	tmp;

	tab = NULL;
	str = NULL;
	tmp = 0;
	size = 1;
	tab = "0123456789";
	tmp = value;
	while (tmp /= base)
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size--] = '\0';
	while (size >= 0)
	{
		str[size--] = tab[value % base];
		value /= base;
	}
	return (str);
}

void					ft_u(t_data *list, va_list arg)
{
	long long int		u;
	char				*str;

	u = 0;
	ft_clean_counts(list);
	u = va_arg(arg, long long int);
	str = ft_conversion_u(u, 10);
	str = ft_accuracy_u(list, str);
	ft_width_d(list, str);
}
