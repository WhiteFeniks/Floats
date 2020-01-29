/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:47:01 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/26 16:47:04 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** версия putstr которая учитывает точнось вывода
*/

void		ft_putstr_precision(char *str, int len, t_data *new)
{
	size_t	i;

	i = -1;
	while (len-- > 0)
		ft_putchar_c(str[++i], new);
}

/*
** версия putchar которая подсчитывает колличество напечатанных символов
** и обнуляет пробел.
*/

void		ft_putchar_space(char c, t_data *new)
{
	write(1, &c, 1);
	new->it.count++;
	new->fl.space = 2;
}

/*
** версия putchar которая подсчитывает колличество напечатанных символов
*/

void		ft_putchar_c(char c, t_data *new)
{
	write(1, &c, 1);
	new->it.count++;
}

/*
** версия putstr которая работает с ft_putchar_c
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
