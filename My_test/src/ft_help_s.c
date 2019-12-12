/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:11:34 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/10 15:59:04 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_first_s(t_data *list, char *s, char *str)
{
	ft_clean_counts(list);
	ft_width_s(list);
	if (list->minus_null == '-')
	{
		while (s[list->j] && list->accuracy-- != 0)
			str[list->i++] = s[list->j++];
		while (list->width-- != 0)
			str[list->i++] = ' ';
		str[list->i] = '\0';
		ft_write_and_clean_s(list, str);
	}
	else if (list->minus_null == '0')
		ft_list_null(list, s, str);
	else if (list->minus_null == '.')
	{
		while (list->width-- != 0)
			str[list->i++] = ' ';
		while (s[list->j] && list->accuracy != 0)
		{
			str[list->i++] = s[list->j++];
			list->accuracy--;
		}
		str[list->i] = '\0';
		ft_write_and_clean_s(list, str);
	}
}

void			ft_second_s(t_data *list, char *s, char *str)
{
	ft_clean_counts(list);
	if (list->point == '0')
	{
		while (s[list->j])
			str[list->i++] = s[list->j++];
		str[list->i] = '\0';
		ft_write_and_clean_s(list, str);
	}
}

void			ft_third_s(t_data *list, char *s, char *str)
{
	ft_clean_counts(list);
	list->len = ft_strlen(s);
	if (list->width >= list->len)
	{
		if (list->point == '0')
			list->width = list->width - list->len;
		ft_only_width(list, s, str);
	}
	else if (list->width < list->len)
	{
		if (list->point == '0')
		{
			while (s[list->j])
				str[list->i++] = s[list->j++];
			str[list->i] = '\0';
			ft_write_and_clean_s(list, str);
		}
		else if (list->point == '.')
			ft_width_null_s(list, s, str);
	}
}

void			ft_fourth_s(t_data *list, char *s, char *str)
{
	ft_clean_counts(list);
	list->len = ft_strlen(s);
	if (list->accuracy > list->len)
	{
		while (s[list->j])
			str[list->i++] = s[list->j++];
	}
	else if (list->accuracy < list->len)
	{
		while (list->accuracy != 0)
		{
			str[list->i++] = s[list->j++];
			list->accuracy--;
		}
	}
	str[list->i] = '\0';
	ft_write_and_clean_s(list, str);
}

void			ft_before(t_data *list, char *s, char *str)
{
	if (list->width != 0 && list->accuracy != 0)
		ft_first_s(list, s, str);
	else if (list->width == 0 && list->accuracy == 0)
		ft_second_s(list, s, str);
	else if (list->width != 0 && list->accuracy == 0)
		ft_third_s(list, s, str);
	else if (list->width == 0 && list->accuracy != 0)
		ft_fourth_s(list, s, str);
}
