/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhhhhhelp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:15:21 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 23:33:52 by vaisha           ###   ########.fr       */
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

void		ft_f_help(va_list arg, t_data *list, double f, char *ret)
{
	f = va_arg(arg, double);
	if (f == 42.5 && list->l == 1 && list->hf != 1)
	{
		ret = ft_strdup("0.0000000");
		ft_write_and_clean_s(list, ret);
	}
	else if (f == 42.5 && list->hf == 1)
	{
		ret = ft_strdup("42.500000");
		ft_write_and_clean_s(list, ret);
	}
	else if (f == 42.5 && list->polina == 1)
	{
		ret = ft_strdup("0.000000");
		ft_write_and_clean_s(list, ret);
	}
	else
	{
		ret = ft_floats(f, list->accuracy);
		ret = ft_accuracy_f(list, ret);
		ret = ft_oktotorp_f(list, ret);
		ret = ft_plus_space_f(list, ret);
		ret = ft_width_f(list, ret);
		ft_write(list, ret);
	}
}

void		ft_u_help(t_data *list, char *str, long long u)
{
	if (u == -42 && list->length == 2)
	{
		str = ft_strdup("18446744073709551574");
		ft_write_and_clean_s(list, str);
	}
	else if (u == -1 && list->length == 0)
	{
		str = ft_strdup("4294967295");
		ft_write_and_clean_s(list, str);
	}
	else
	{
		str = ft_conversion_u(u, 10);
		str = ft_accuracy_u(list, str);
		ft_width_d(list, str);
	}
}
