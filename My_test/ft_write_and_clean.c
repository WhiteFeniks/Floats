/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_and_clean.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:43:06 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 13:20:29 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_clean_counts(t_data *list)
{
	list->i = 0;
	list->j = 0;
}

void		ft_clean_list(t_data *list)
{
	list->percent = '.';
	list->plus_space = '.';
	list->minus_null = '.';
	list->hash = '.';
	list->width = 0;
	list->accuracy = 0;
	list->length = 0;
	list->type = '.';
	list->point = '0';
	list->ret = 0;
	list->len = 0;
	list->i = 0;
	list->j = 0;
	list->tmp = 0;
	list->nol = 0;
	list->hf = 0;
	list->ret = 0;
}

void		ft_clean_all(t_data *list)
{
	free(list);
	list = NULL;
}

void		ft_clean_s(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

void		ft_write_and_clean_s(t_data *list, char *s)
{
	ft_clean_counts(list);
	while (s && s[list->i])
	{
		write(1, &s[list->i++], 1);
		list->ret++;
	}
	ft_clean_s(s);
}
