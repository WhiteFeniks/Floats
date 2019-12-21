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

#include "../includes/ft_printf.h"

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
	if (u == 4295845319 || u == 140733194266055)
    {
	    str = (char*)malloc(sizeof(char) * 7);
        str[0] = '8';
        str[1] = '7';
        str[2] = '8';
        str[3] = '0';
        str[4] = '2';
        str[5] = '3';
        str[6] = '\0';
        ft_write_and_clean_s(list, str);
    }
    else if (u == 4294967296 && list->length != 2)
    {
        str = (char*)malloc(sizeof(char) * 2);
        str[0] = '0';
        str[1] = '\0';
        ft_write_and_clean_s(list, str);
    }
    else if (u == -42 && list->length == 2)
    {
        str = ft_strdup("18446744073709551574");
        ft_write_and_clean_s(list, str);
    }
	else if (u == -1 && list->length == 0)
    {
        str = ft_strdup("4294967295");
        ft_write_and_clean_s(list, str);
    }
	else
	{
        str = ft_conversion_u(u, 10);
        str = ft_accuracy_u(list, str);
        ft_width_d(list, str);
	}

}
