/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:04:51 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/12 17:46:05 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_allocation(t_data *list, va_list arg)
{
	if (list->type == 'c' || list->type == 'c')
		ft_c(list, arg);
	else if (list->type == 's' || list->type == 'S')
		ft_s(list, arg);
	else if (list->type == 'p' || list->type == 'P')
		ft_p(list, arg);
	else if (list->type == 'd' || list->type == 'i' || list->type == 'D'
			|| list->type == 'I')
		ft_d_i(list, arg);
	else if (list->type == 'o' || list->type == 'O')
		ft_o(list, arg);
	else if (list->type == 'u' || list->type == 'U')
		ft_u(list, arg);
	else if (list->type == 'x' || list->type == 'X')
		ft_x(list, arg);
	else if (list->type == 'f' || list->type == 'F')
		ft_f(list, arg);
    else if (list->type == 'l' || list->type == 'L')
        ft_Lf(list, arg);
}
