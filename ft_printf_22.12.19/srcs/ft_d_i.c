/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:01:15 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/10 14:45:40 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				ft_plus_space(t_data *list, char *tmp)
{
	char			*ret;

	ft_clean_counts(list);
	ret = NULL;
	list->len = ft_strlen(tmp);
	if (list->plus_space == '.' || tmp[0] == '-')
		ret = ft_strdup(tmp);
	else if (list->plus_space != '.' && tmp[0] != '-')
	{
		ret = (char *)malloc(sizeof(char) * list->len + 2);
		ret[list->i++] = list->plus_space;
		while (tmp[list->j])
			ret[list->i++] = tmp[list->j++];
		ret[list->i] = '\0';
	}
	ft_clean_s(tmp);
	ft_width_d(list, ret);
}

char				*ft_accuracy(t_data *list, char *tmp, char *ret)
{
	list->tmp = list->accuracy;
	if (list->accuracy >= list->len)
	{
		ret = (char*)malloc(sizeof(char) * list->accuracy + 2);
		if (tmp[list->i] == '-')
		{
			ret[list->i++] = '-';
			list->len--;
			list->j++;
		}
		while (list->accuracy-- > list->len)
			ret[list->i++] = '0';
		while (tmp[list->j])
			ret[list->i++] = tmp[list->j++];
		ret[list->i] = '\0';
	}
	else if (list->accuracy == 0 && list->point == '.' && tmp[0] == '0')
	{
		ret = (char*)malloc(sizeof(char) * 1);
		ret[0] = '\0';
	}
	else
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	return (ret);
}

char				*ft_conversion_d(long long int n)
{
	int				i;
	char			*res;
	long			a;

	i = 1;
	a = n;
	if (n < 0)
		i++;
	while ((n = n / 10) != 0)
		i++;
	if ((res = ft_strnew(i)))
	{
		(a == 0) ? (res[0] = '0') : 0;
		if (a < 0)
		{
			res[0] = '-';
			a = a * (-1);
		}
		while (a != 0)
		{
			res[--i] = a % 10 + '0';
			a = a / 10;
		}
	}
	return (res);
}

long long			ft_length_d(t_data *list, va_list arg)
{
	long long int	res;

	res = 0;
	if (list->length == 4)
		res = va_arg(arg, long long int);
	else if (list->length == 2)
		res = va_arg(arg, long int);
	else
		res = va_arg(arg, int);
	return (res);
}

void				ft_d_i(t_data *list, va_list arg)
{
	long long int	value;
	char			*tmp;
	char			*ret;

	ret = NULL;
	value = 0;
	tmp = NULL;
	value = ft_length_d(list, arg);
	if ((list->type == 'i' && list->length == 5) || list->length == 3)
		value = ft_help_i(list, value);
	tmp = ft_conversion_d(value);
	list->len = ft_strlen(tmp);
	ft_clean_counts(list);
	tmp = ft_accuracy(list, tmp, ret);
	ft_plus_space(list, tmp);
}
