/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:50:45 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/06 14:29:52 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_minus_null(t_data *list, char *tmp, char *res)
{
	if (list->minus_null == '-')
	{
		write(1, &tmp[0], 1);
		list->ret++;
		while (list->width-- != 0)
			res[list->i++] = ' ';
		res[list->i] = '\0';
		ft_clean_s(tmp);
		ft_write_and_clean_s(list, res);
	}
	else if (list->minus_null == '0')
	{
		while (list->width-- != 0)
			res[list->i++] = '0';
		res[list->i] = '\0';
		ft_write_and_clean_s(list, res);
		write(1, &tmp[0], 1);
		ft_clean_s(tmp);
	}
}

void	ft_width_null(t_data *list, char *tmp)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * list->width);
	list->width--;
	ft_clean_counts(list);
	if (list->minus_null == '-')
		ft_minus_null(list, tmp, ret);
	else if (list->minus_null == '0')
		ft_minus_null(list, tmp, ret);
	else if (list->minus_null == '.')
	{
		while (list->width-- != 0)
			ret[list->i++] = ' ';
		ret[list->i] = '\0';
		list->ret++; 
		ft_write_and_clean_s(list, ret);
		write(1, &tmp[0], 1);
		ft_clean_s(tmp);
	}
}

void	ft_null(t_data *list, char *str)
{
	ft_clean_counts(list);
	if (list->width == 0)
	{
		write(1, &str[0], 1);
		ft_clean_s(str);
		list->ret++;
	}
	else if (list->width != 0)
		ft_width_null(list, str);
}
