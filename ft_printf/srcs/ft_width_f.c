/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:42:36 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 22:00:35 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_accuracy_f2(t_data *list, char *tmp, char *ret)
{
	ret = (char*)malloc(sizeof(char) * list->len + 1);
	ft_clean_counts(list);
	while (tmp[list->i] && tmp[list->i] != '.')
		ret[list->j++] = tmp[list->i++];
	if (tmp[list->i] == '.')
	{
		if (list->point == '.' && list->accuracy == 0)
		{
			ret[list->j] = '\0';
			return (ret);
		}
		else
		{
			ret[list->j++] = tmp[list->i++];
			while (list->accuracy > 0)
			{
				ret[list->j++] = tmp[list->i++];
				list->accuracy--;
			}
		}
	}
	ret[list->j] = '\0';
	return (ret);
}

char		*ft_null_f(t_data *list, char *tmp, char *res)
{
	ft_clean_counts(list);
	if (tmp[list->i] == '-' || tmp[list->i] == '+' || tmp[list->i] == ' ')
		res[list->i++] = tmp[list->j++];
	while (list->width-- != 0)
		res[list->i++] = '0';
	while (tmp[list->j])
		res[list->i++] = tmp[list->j++];
	res[list->i] = '\0';
	ft_clean_s(tmp);
	return (res);
}

char		*ft_minus_f(t_data *list, char *tmp, char *res)
{
	ft_clean_counts(list);
	while (tmp[list->j])
		res[list->i++] = tmp[list->j++];
	while (list->width-- != 0)
		res[list->i++] = ' ';
	res[list->i] = '\0';
	ft_clean_s(tmp);
	return (res);
}

char		*ft_point_f(t_data *list, char *tmp, char *ret)
{
	ft_clean_counts(list);
	while (list->width-- != 0)
		ret[list->i++] = ' ';
	while (tmp[list->j])
		ret[list->i++] = tmp[list->j++];
	ret[list->i] = '\0';
	ft_clean_s(tmp);
	return (ret);
}

char		*ft_width_f(t_data *list, char *tmp)
{
	char	*res;

	res = NULL;
	list->len = ft_strlen(tmp);
	ft_clean_counts(list);
	if (list->width <= list->len)
		res = ft_strdup(tmp);
	else if (list->width > list->len)
	{
		res = (char*)malloc(sizeof(char) * list->width + 1);
		list->width = list->width - list->len;
		if (list->minus_null == '.')
			res = ft_point_f(list, tmp, res);
		else if (list->minus_null == '-')
			res = ft_minus_f(list, tmp, res);
		else if (list->minus_null == '0')
			res = ft_null_f(list, tmp, res);
	}
	return (res);
}
