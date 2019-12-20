/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:00:29 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/10 15:41:33 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_c(t_data *list, va_list arg)
{
	char	*s;

	s = NULL;
	ft_clean_counts(list);
	s = (char*)malloc(sizeof(char) * 2);
	s[0] = va_arg(arg, int);
	s[1] = '\0';
	if ((s[0] && s[0] == 0) || s[0] == '\0')
		ft_null(list, s);
	else
	{
		if (list->width == 0)
			ft_write_and_clean_s(list, s);
		else if (list->width != 0)
			ft_width_d(list, s);
	}
}
