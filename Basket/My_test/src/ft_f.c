/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:02:16 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/12 16:58:18 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_f(t_data *list, va_list arg)
{
	double		f;
	char			*ret;

	f = 0;
	ret = NULL;
	f = va_arg(arg, double);
	ret = ft_floats(list, f);
	ft_write_and_clean_s(list, ret);
	//ft_width_d(list, ret);
}
