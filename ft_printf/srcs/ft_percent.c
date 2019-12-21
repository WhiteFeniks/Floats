/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:36:02 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/21 21:46:07 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_first_procent(t_data *list, char *s, int x)
{
	if (list->minus_null == '-')
	{
		s[x++] = '%';
		while (list->width && list->width != 1)
		{
			s[x++] = ' ';
			list->width--;
		}
	}
	s[x] = '\0';
	x = 0;
	while (s[x])
	{
		write(1, &s[x++], 1);
		list->ret++;
	}
}

void		ft_second_procent(t_data *list, char *s, int x)
{
	if (list->minus_null == '0')
	{
		while (list->width && list->width != 1)
		{
			s[x++] = '0';
			list->width--;
		}
		s[x++] = '%';
	}
	s[x] = '\0';
	x = 0;
	while (s[x])
	{
		write(1, &s[x++], 1);
		list->ret++;
	}
}

void		ft_third_procent(t_data *list, char *s, int x)
{
	if (list->minus_null == '.')
	{
		while (list->width && list->width != 1)
		{
			s[x++] = ' ';
			list->width--;
		}
		s[x++] = '%';
	}
	s[x] = '\0';
	x = 0;
	while (s[x])
	{
		write(1, &s[x++], 1);
		list->ret++;
	}
}

int			ft_procent(t_data *list, int i)
{
	char	*s;
	int		x;

	x = 0;
	s = (char*)malloc(sizeof(char) * list->width + 1);
	if (list->minus_null == '-')
		ft_first_procent(list, s, x);
	else if (list->minus_null == '0')
		ft_second_procent(list, s, x);
	else if (list->minus_null == '.')
		ft_third_procent(list, s, x);
	ft_clean_s(s);
	return (++i);
}
