/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:52:09 by doberyn           #+#    #+#             */
/*   Updated: 2019/11/03 18:52:11 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ft_type_conversion_signed - функция которая определяет
** тип и записывает значение. Работает со знаковыми значениями(signed).
** norme	✓
** fixed	✓
*/

void		ft_type_conversion_signed(t_sig *sig, t_data *new)
{
	if (new->length == 1)
		sig->data = va_arg(new->bs.arg, long int);
	else if (new->length == 2)
		sig->data = va_arg(new->bs.arg, long long int);
	else if (new->length == 3)
		sig->data = (short int)va_arg(new->bs.arg, int);
	else if (new->length == 4)
		sig->data = (signed char)va_arg(new->bs.arg, int);
	else
		sig->data = va_arg(new->bs.arg, int);
}

/*
** ft_print_dec - функция которая обрабатывает десятичные типы %d и %i
** norme	✓
** fixed	✓
*/

void		ft_print_dec(t_data *new)
{
	t_sig	sig;

	ft_type_conversion_signed(&sig, new);
	ft_mutual_exclusion(new, sig.data, 'd');
	sig.sign = (sig.data < 0) ? '-' : '+';
	sig.str = ft_itoa_base_sig(sig.data, 10);
	sig.len = (new->fl.plus != 0 || sig.sign == '-') ?
				(int)ft_strlen(sig.str) + 1 : (int)ft_strlen(sig.str);
	sig.len = (!(sig.data == 0 && new->prec == 0 && new->dot != 0)) ?
				sig.len : sig.len - 1;
	if (new->fl.space == 1 && (new->width <= sig.len || new->fl.minus != 0))
		ft_putchar_space(' ', new);
	if (new->width > sig.len && new->fl.minus == 0)
		sig.sign = ft_width(sig.sign, sig.len, new);
	if ((new->fl.plus != 0 && new->fl.zero == 0) || sig.sign == '-')
		ft_putchar_c(sig.sign, new);
	if (new->prec >= sig.len)
		ft_precision(sig.sign, sig.len, new);
	if (!(sig.data == 0 && new->prec == 0 && new->dot != 0))
		ft_putstr_c(sig.str, new);
	if (new->width > sig.len && new->fl.minus != 0)
		ft_width(sig.sign, sig.len, new);
	free(sig.str);
}
