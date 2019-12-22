/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:37:08 by doberyn           #+#    #+#             */
/*   Updated: 2019/11/03 16:37:11 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ft_putstr_precision - модифицированная версия putstr
** которая учитывает точнось вывода.
** norme  ✓
** fixed  ✓
*/

void		ft_putstr_precision(char *str, int len, t_data *new)
{
	size_t	i;

	i = -1;
	while (len-- > 0)
		ft_putchar_c(str[++i], new);
}

/*
** ft_putchar_space - модифицированная версия putchar
** которая подсчитывает колличество напечатанных символов
** и обнуляет пробел.
** norme
** fix 	  ✓
*/

void		ft_putchar_space(char c, t_data *new)
{
	write(1, &c, 1);
	new->it.count++;
	new->fl.space = 2;
}

/*
** ft_putchar_c - модифицированная версия putchar
** которая подсчитывает колличество напечатанных символов.
** norme
** fix 	  ✓
*/

void		ft_putchar_c(char c, t_data *new)
{
	write(1, &c, 1);
	new->it.count++;
}

/*
** ft_putstr_c - модифицированная версия putstr
** которая работает с ft_putchar_c.
** norme  ✓
** fixed  ✓
*/

void		ft_putstr_c(char *s, t_data *new)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_c(s[i], new);
		i++;
	}
}
