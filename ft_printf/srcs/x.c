/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:05:10 by doberyn           #+#    #+#             */
/*   Updated: 2019/11/03 16:05:14 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ft_toupper - функция которая переводит символ в верхний регистр.
** norme	✓
** fixed	✓
*/

char		*ft_toupper(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ' ';
		i++;
	}
	return (str);
}

/*
** ft_formating_x - функция которая формирует
** строку и оправляет их на вывод.
** norme	✓
** fixed	✓
*/

void		ft_formating_x(t_uns *uns, t_data *new)
{
	t_hex	hex;

	hex.shlen = (new->fl.sharp == 0) ? uns->len : uns->len + 2;
	hex.prlen = (new->prec > uns->len) ? new->prec : 0;
	hex.prlen = (new->fl.sharp != 0) ? hex.prlen + 2 : hex.prlen;
	ft_mutual_exclusion_prec(uns->len, new);
	ft_mutual_exclusion_width(hex.shlen, new);
	hex.size = ft_get_size(uns, new);
	hex.str = (char *)malloc(sizeof(char) * hex.size + 1);
	hex.str[hex.size] = '\0';
	ft_memset(hex.str, ' ', hex.size);
	if (new->fl.sharp != 0)
		hex.str = ft_sharp_x(uns->len, hex.str, new);
	if (new->width > hex.prlen)
		hex.str = ft_width_x(uns->len, hex.str, new);
	if (new->prec > uns->len)
		hex.str = ft_precision_x(uns->len, hex.str, new);
	hex.str = ft_add_x(uns->len, hex.str, uns->str, new);
	hex.str = (new->type == 'X') ? ft_toupper(hex.str) : hex.str;
	ft_putstr_c(hex.str, new);
	free(hex.str);
}

/*
** ft_print_x - функция которая обрабатывает шестнадцатеричный
** знакоывй тип %x и %X.
** norme	✓
** fixed	✓
*/

void		ft_print_x(t_data *new)
{
	t_uns	uns;

	ft_type_conversion_unsigned(&uns, new);
	ft_mutual_exclusion(new, (long long)uns.data, 'x');
	uns.str = ft_itoa_base_unsig(uns.data, 16);
	uns.len = ft_strlen(uns.str);
	ft_formating_x(&uns, new);
	free(uns.str);
}
