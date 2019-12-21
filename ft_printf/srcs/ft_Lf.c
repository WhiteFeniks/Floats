/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Lf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:34:11 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 21:36:00 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"

char				*ft_lf(t_data *list, va_list arg)
{
	long double		lf;
	char			*ret;

	lf = 0;
	ret = NULL;
	lf = va_arg(arg, long double);
	ret = ft_Lf_floats(lf, list->accuracy);
	return (ret);
}
