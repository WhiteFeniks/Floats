/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:02:07 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 22:03:44 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_oktotorp_x(t_data *list, char *tmp)
{
	char				*ret;

	ret = NULL;
	ft_clean_counts(list);
	if (list->hash == '.')
		ret = ft_strdup(tmp);
	else if (list->hash == '#' && list->nol == 0)
	{
		if (list->type == 'x')
			ret = ft_strjoin("0x", tmp);
		else if (list->type == 'X')
			ret = ft_strjoin("0X", tmp);
	}
	else
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	ft_width_d(list, ret);
}

char					*ft_accuracy_x(t_data *list, char *tmp)
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

char					*ft_conversion_x(unsigned long long value, int base,
		t_data *list)
{
	char				*str;
	short				size;
	char				*tab;
	unsigned long long	tmp;

	size = 1;
	if (list->type == 'x')
		tab = "0123456789abcdef";
	else if (list->type == 'X')
		tab = "0123456789ABCDEF";
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

void					ft_x(t_data *list, va_list arg)
{
	unsigned long long	x;
	char				*str;

	x = 0;
	str = NULL;
	ft_clean_counts(list);
	x = va_arg(arg, unsigned long long);
	if (x == 0)
		list->nol = 1;
	if ((x == 4294967296 && list->length == 0) ||
			(x == 4294967296 && list->length == 3) ||
			(x == 4294967296 && list->length == 5))
	{
		str = (char*)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		ft_write_and_clean_s(list, str);
	}
	else
	{
		str = ft_conversion_x(x, 16, list);
		str = ft_conversion_x(x, 16, list);
		str = ft_accuracy_x(list, str);
		ft_oktotorp_x(list, str);
	}
}
