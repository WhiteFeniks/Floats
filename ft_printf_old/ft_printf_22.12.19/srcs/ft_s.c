/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:00:52 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/10 15:56:04 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_width_null_s(t_data *list, char *tmp, char *str)
{
	ft_clean_counts(list);
	if (list->minus_null == '.')
		ft_list_null3(list, tmp, str);
	else if (list->minus_null == '-')
		ft_list_null3(list, tmp, str);
	else if (list->minus_null == '0')
	{
		while (list->width-- != 0)
			str[list->i++] = '0';
		if (list->point == '0')
		{
			while (tmp[list->j])
				str[list->i++] = tmp[list->j++];
		}
		str[list->i] = '\0';
		ft_write_and_clean_s(list, str);
	}
}

void		ft_only_width(t_data *list, char *s, char *str)
{
	ft_clean_counts(list);
	if (list->minus_null == '.')
		ft_list_null2(list, s, str);
	else if (list->minus_null == '-')
	{
		if (list->point == '0')
		{
			while (s[list->j])
				str[list->i++] = s[list->j++];
		}
		while (list->width-- != 0)
			str[list->i++] = ' ';
		str[list->i] = '\0';
		ft_write_and_clean_s(list, str);
	}
	else if (list->minus_null == '0')
		ft_list_null(list, s, str);
}

void		ft_width_s(t_data *list)
{
	if (list->accuracy != 0 && list->len != 0)
	{
		if (list->width >= list->accuracy && list->accuracy >= list->len)
			list->width = list->width - list->len;
		else if (list->width >= list->accuracy && list->accuracy <= list->len)
			list->width = list->width - list->accuracy;
		else if ((list->width <= list->accuracy && list->accuracy <= list->len)
			|| (list->width <= list->accuracy && list->accuracy >= list->len))
			list->width = 0;
	}
	else
	{
		if (list->width >= list->len)
			list->width = list->width - list->len;
		else if (list->width < list->len)
			list->width = 0;
	}
}

void		ft_s(t_data *list, va_list arg)
{
	char	*s;
	char	*str;

	s = NULL;
	str = NULL;
	list->len = 0;
	if ((s = va_arg(arg, char *)) != NULL)
	{
		list->len = ft_strlen(s);
		if ((list->width > list->len) || (list->width == list->len))
			str = ((char *)malloc(sizeof(char) * (list->width + 1)));
		else if (list->width < list->len)
			str = ((char *)malloc(sizeof(char) * (list->len + 1)));
		ft_before(list, s, str);
	}
	else if (s == NULL)
		ft_null_s(list, str);
}
