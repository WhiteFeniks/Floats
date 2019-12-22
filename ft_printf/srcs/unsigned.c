/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:37:34 by doberyn           #+#    #+#             */
/*   Updated: 2019/11/03 18:44:13 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ft_type_conversion_unsigned - функция которая определяет
** тип и записывает значение. Работает с беззнаковыми значениями(unsigned).
** norme	✓
** fixed	✓
*/

void		ft_type_conversion_unsigned(t_uns *uns, t_data *new)
{
	if (new->length == 1)
		uns->data = va_arg(new->bs.arg, unsigned long int);
	else if (new->length == 2)
		uns->data = va_arg(new->bs.arg, unsigned long long int);
	else if (new->length == 3)
		uns->data = (unsigned short int)va_arg(new->bs.arg, unsigned int);
	else if (new->length == 4)
		uns->data = (unsigned char)va_arg(new->bs.arg, unsigned int);
	else
		uns->data = va_arg(new->bs.arg, unsigned int);
}

/*
** ft_print_o - функция которая обрабатывает восьмеричный беззнакоывй тип %o
** norme	✓
** fixed	✓
*/

void		ft_print_o(t_data *new)
{
	t_uns	uns;

	ft_type_conversion_unsigned(&uns, new);
	ft_mutual_exclusion(new, (long long)uns.data, 'o');
	uns.str = ft_itoa_base_unsig(uns.data, 8);
	if (new->fl.sharp != 0 && uns.data != 0)
	{
		uns.tmp = uns.str;
		uns.str = ft_strjoin("0", uns.str);
		free(uns.tmp);
	}
	uns.len = (!(uns.data == 0 && new->prec == 0 && new->dot != 0 &&
			new->fl.sharp == 0)) ? (int)ft_strlen(uns.str) :
				(int)ft_strlen(uns.str) - 1;
	if (new->width > uns.len && new->fl.minus == 0)
		ft_width('+', uns.len, new);
	if (new->prec > uns.len)
		ft_precision('+', uns.len, new);
	if (!(uns.data == 0 && new->prec == 0 && new->dot != 0 &&
		new->fl.sharp == 0))
		ft_putstr_c(uns.str, new);
	if (new->width > uns.len && new->fl.minus != 0)
		ft_width('+', uns.len, new);
	free(uns.str);
}

/*
** ft_print_u - функция для обработки и печати целого
** без знака в десятичном виде типа %u.
** norme	✓
** fixed	✓
*/

void		ft_print_u(t_data *new)
{
	t_uns	uns;

	ft_type_conversion_unsigned(&uns, new);
	ft_mutual_exclusion(new, (long long)uns.data, 'u');
	uns.sign = '+';
	uns.str = ft_itoa_base_unsig(uns.data, 10);
	uns.len = (new->fl.plus != 0 || uns.sign == '-') ?
			(int)ft_strlen(uns.str) + 1 : (int)ft_strlen(uns.str);
	uns.len = (!(uns.data == 0 && new->prec == 0 && new->dot != 0)) ?
			uns.len : uns.len - 1;
	if (new->width > uns.len && new->fl.minus == 0)
		uns.sign = ft_width(uns.sign, uns.len, new);
	if (new->prec > uns.len)
		ft_precision(uns.sign, uns.len, new);
	if (!(uns.data == 0 && new->prec == 0 && new->dot != 0))
		ft_putstr_c(uns.str, new);
	if (new->width > uns.len && new->fl.minus != 0)
		ft_width(uns.sign, uns.len, new);
	free(uns.str);
}
