/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:01:05 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/09 15:57:26 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_null_p(char *tmp, t_data *list)
{
	char				*res;

	res = NULL;
	ft_clean_counts(list);
	res = (char*)malloc(sizeof(char) * 3);
	res[list->i++] = tmp[0];
	res[list->i++] = tmp[1];
	res[list->i] = '\0';
	return (res);
}

char					*ft_accuracy_p(t_data *list, char *tmp)
{
	char				*ret;

	ret = NULL;
	ft_clean_counts(list);
	if (list->accuracy == 0 && tmp[2] == '0' && list->point == '.')
		ret = ft_null_p(tmp, list);
	else if (list->accuracy != 0 && list->accuracy >= list->len)
	{
		ret = (char*)malloc(sizeof(char) * list->accuracy + 3);
		ret[list->i++] = tmp[list->j++];
		ret[list->i++] = tmp[list->j++];
		while (list->accuracy-- > list->len)
			ret[list->i++] = '0';
		while (tmp[list->j])
			ret[list->i++] = tmp[list->j++];
		ret[list->i] = '\0';
	}
	else
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	return (ret);
}

char					*ft_conversion_p(unsigned long long value, int base)
{
	char				*str;
	short				size;
	char				*tab;
	unsigned long long	tmp;

	size = 1;
	tab = "0123456789abcdef";
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

void					ft_p(t_data *list, va_list arg)
{
	unsigned long long	p;
	char				*tmp;
	char				*str;

	tmp = NULL;
	p = va_arg(arg, unsigned long long);
	tmp = ft_conversion_p(p, 16);
	list->len = (ft_strlen(tmp));
	str = (char*)malloc(sizeof(char) * list->len + 3);
	str[0] = '0';
	str[1] = 'x';
	str = ft_strjoin(str, tmp);
	ft_clean_s(tmp);
	str = ft_accuracy_p(list, str);
	ft_width_d(list, str);
}
