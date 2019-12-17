/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:02:16 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/12 17:49:20 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void		ft_write(t_data *list, char *s)
{
    ft_clean_counts(list);
    while (s && s[list->i])
    {
        write(1, &s[list->i++], 1);
        list->ret++;
    }
}

void		ft_f(t_data *list, va_list arg)
{
    double		f;
    char			*ret;

    f = 0;
    ret = NULL;
    f = va_arg(arg, double);
    ret = ft_floats(f, list->accuracy);
    ft_write(list, ret);
}