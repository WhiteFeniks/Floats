/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_s2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:51:25 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/18 15:28:19 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_list_null(t_data *list, char *s, char *str)
{
	while (list->width-- != 0)
		str[list->i++] = '0';
	while (s[list->j])
		str[list->i++] = s[list->j++];
	str[list->i] = '\0';
	ft_write_and_clean_s(list, str);
}

void	ft_list_null2(t_data *list, char *s, char *str)
{
	if (list->minus_null == '0')
	{
		while (list->width-- != 0)
			str[list->i++] = '0';
		if (list->point == '0')
		{
			while (s[list->j])
				str[list->i++] = s[list->j++];
		}
	}
	else if (list->minus_null == '.')
	{
		while (list->width-- != 0)
			str[list->i++] = ' ';
		if (list->point == '0')
		{
			while (s[list->j])
				str[list->i++] = s[list->j++];
		}
	}
	str[list->i] = '\0';
	ft_write_and_clean_s(list, str);
}

void	ft_list_null3(t_data *list, char *tmp, char *str)
{
	if (list->minus_null == '.')
	{
		while (list->width-- != 0)
			str[list->i++] = ' ';
		if (list->point == '0')
		{
			while (tmp[list->j])
				str[list->i++] = tmp[list->j++];
		}
	}
	else if (list->minus_null == '-')
	{
		if (list->point == '0')
		{
			while (tmp[list->j])
				str[list->i++] = tmp[list->j++];
		}
		while (list->width-- != 0)
			str[list->i++] = ' ';
	}
	str[list->i] = '\0';
	ft_write_and_clean_s(list, str);
}
