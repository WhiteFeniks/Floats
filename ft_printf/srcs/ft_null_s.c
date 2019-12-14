/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:49:18 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/10 15:42:48 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_first_null(t_data *list, char *tmp, char *str)
{
	ft_clean_counts(list);
	ft_width_s(list);
	if (list->minus_null == '-')
	{
		while (tmp[list->j] && list->accuracy-- != 0)
			str[list->i++] = tmp[list->j++];
		while (list->width-- != 0)
			str[list->i++] = ' ';
	}
	else if (list->minus_null != '-')
	{
		while (list->width-- != 0)
			str[list->i++] = ' ';
		while (tmp[list->j] && list->accuracy != 0)
		{
			str[list->i++] = tmp[list->j++];
			list->accuracy--;
		}
	}
	str[list->i] = '\0';
	ft_write_and_clean_s(list, str);
}

void			ft_second_null(t_data *list, char *tmp, char *str)
{
	ft_clean_counts(list);
	if (list->point == '0')
	{
		while (tmp[list->j])
			str[list->i++] = tmp[list->j++];
		str[list->i] = '\0';
		ft_write_and_clean_s(list, str);
	}
}

void			ft_third_null(t_data *list, char *tmp, char *str)
{
	ft_clean_counts(list);
	if (list->width >= list->len)
	{
		if (list->point == '0')
			list->width = list->width - list->len;
		ft_width_null_s(list, tmp, str);
	}
	else if (list->width < list->len)
	{
		if (list->point == '0')
		{
			while (tmp[list->j])
				str[list->i++] = tmp[list->j++];
			str[list->i] = '\0';
			ft_write_and_clean_s(list, str);
		}
		else if (list->point == '.')
			ft_width_null_s(list, tmp, str);
	}
}

void			ft_fourth_null(t_data *list, char *tmp, char *str)
{
	ft_clean_counts(list);
	if (list->accuracy > list->len)
	{
		while (tmp[list->j])
			str[list->i++] = tmp[list->j++];
	}
	else if (list->accuracy < list->len)
	{
		while (list->accuracy != 0)
		{
			str[list->i++] = tmp[list->j++];
			list->accuracy--;
		}
	}
	str[list->i] = '\0';
	ft_write_and_clean_s(list, str);
}

void			ft_null_s(t_data *list, char *str)
{
	char	*tmp;

	tmp = NULL;
	ft_clean_counts(list);
	list->len = 6;
	if ((list->width > list->len) || (list->width == list->len))
		str = ((char *)malloc(sizeof(char) * (list->width + 1)));
	else if (list->width < list->len)
		str = ((char *)malloc(sizeof(char) * (list->len + 1)));
	tmp = (char *)malloc(sizeof(char) * 7);
	tmp[list->i++] = '(';
	tmp[list->i++] = 'n';
	tmp[list->i++] = 'u';
	tmp[list->i++] = 'l';
	tmp[list->i++] = 'l';
	tmp[list->i++] = ')';
	tmp[list->i] = '\0';
	if (list->width != 0 && list->accuracy != 0)
		ft_first_null(list, tmp, str);
	else if (list->width == 0 && list->accuracy == 0)
		ft_second_null(list, tmp, str);
	else if (list->width != 0 && list->accuracy == 0)
		ft_third_null(list, tmp, str);
	else if (list->width == 0 && list->accuracy != 0)
		ft_fourth_null(list, tmp, str);
}
