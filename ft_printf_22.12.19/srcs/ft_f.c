/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:02:16 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/22 01:27:48 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*ft_accuracy_f_help(t_data *list, char *tmp, char *ret,
						char *t)
{
	list->accuracy = list->accuracy - list->len;
	t = (char*)malloc(sizeof(char) * list->accuracy + 1);
	while (list->accuracy--)
		t[list->j++] = '0';
	t[list->j] = '\0';
	ret = ft_strdup(t);
	free(t);
	t = ft_strdup(ret);
	free(ret);
	ret = ft_strjoin(tmp, t);
	free(t);
	return (ret);
}

char				*ft_accuracy_f(t_data *list, char *tmp)
{
	char			*ret;
	char			*t;

	ret = NULL;
	t = NULL;
	ft_clean_counts(list);
	while (tmp && tmp[list->i] != '.')
		list->i++;
	if (tmp[list->i] == '.')
	{
		list->i++;
		while (tmp[list->i++])
			list->len++;
		if (list->accuracy > list->len)
			ret = ft_accuracy_f_help(list, tmp, ret, t);
		else if (list->accuracy <= list->len)
			ret = ft_accuracy_f2(list, tmp, ret);
	}
	else
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	return (ret);
}

char				*ft_plus_space_f(t_data *list, char *tmp)
{
	char			*ret;

	ret = NULL;
	ft_clean_counts(list);
	list->len = ft_strlen(tmp);
	if (list->plus_space != '.' && tmp[0] != '-')
	{
		ret = (char*)malloc(sizeof(char) * list->len + 2);
		if (list->plus_space == '+')
			ret[list->i++] = '+';
		else if (list->plus_space == ' ')
			ret[list->i++] = ' ';
		while (tmp[list->j])
			ret[list->i++] = tmp[list->j++];
		ret[list->i++] = '\0';
	}
	else if (list->plus_space == '.' || tmp[0] == '-')
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	return (ret);
}

char				*ft_oktotorp_f(t_data *list, char *tmp)
{
	char			*ret;

	ret = NULL;
	ft_clean_counts(list);
	list->len = ft_strlen(tmp);
	if (list->hash == '#')
	{
		if (ft_strchr(tmp, '.') != 0)
			ret = ft_strdup(tmp);
		else
		{
			ret = (char*)malloc(sizeof(char) * list->len + 2);
			while (tmp[list->j])
				ret[list->i++] = tmp[list->j++];
			ret[list->i++] = '.';
			ret[list->i++] = '\0';
		}
	}
	else
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	return (ret);
}

void				ft_f(t_data *list, va_list arg)
{
	double			f;
	char			*ret;

	f = 0;
	ret = NULL;
	if (list->accuracy == 0 && list->point != '.')
		list->accuracy = 6;
	if (list->length == 3 && list->l == 0 && list->hf != 1 && list->polina != 1)
	{
		ret = ft_lf(list, arg);
		ret = ft_accuracy_f(list, ret);
		ret = ft_oktotorp_f(list, ret);
		ret = ft_plus_space_f(list, ret);
		ret = ft_width_f(list, ret);
		ft_write(list, ret);
		free(ret);
	}
	else
		ft_f_help(arg, list, f, ret);
}
