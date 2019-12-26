/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:16:42 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/26 15:18:04 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ф-ия которая определяет длину строки
*/

int			ft_get_size(t_uns *uns, t_data *new)
{
	int		size;
	int		len;

	len = (new->fl.sharp != 0) ? uns->len + 2 : uns->len;
	size = 0;
	if (new->prec == 0 && uns->data == 0 && new->width == 0)
		size = 0;
	else if (new->prec == 0 && uns->data == 0 && new->width != 0)
		size = new->width;
	else if ((new->width == 0 || new->width < len)
			&& (new->prec == 0 || new->prec < len))
		size = len;
	else if (new->width > len && new->prec == 0)
		size = new->width;
	else if (new->prec >= uns->len)
	{
		size = (new->fl.sharp != 0) ? new->prec + 2 : new->prec;
		if (new->width > size)
			size = new->width;
	}
	return (size);
}

/*
** ф-ия которая определяет в какое место вставить точность
*/

char		*ft_precision_x(int len, char *str, t_data *new)
{
	char	*prec;

	prec = (char *)malloc(sizeof(char) * new->prec - len);
	prec[new->prec] = '\0';
	ft_memset(prec, '0', new->prec - len);
	if (new->prec > len && new->fl.sharp == 0)
	{
		if (new->width < new->prec)
			ft_memlcpy(str, prec, new->prec - len, 0);
		else if (new->width >= new->prec && new->fl.minus == 0)
			ft_memlcpy(str, prec, new->prec - len, new->width - new->prec);
		else if (new->width >= new->prec && new->fl.minus != 0)
			ft_memlcpy(str, prec, new->prec - len, 0);
	}
	else if (new->prec > len && new->fl.sharp != 0)
	{
		if (new->width < new->prec)
			ft_memlcpy(str, prec, new->prec - len, 2);
		else if (new->width >= new->prec + 2 && new->fl.minus == 0)
			ft_memlcpy(str, prec, new->prec - len, new->width - new->prec);
		else if (new->width >= new->prec + 2 && new->fl.minus != 0)
			ft_memlcpy(str, prec, new->prec - len, 2);
	}
	free(prec);
	return (str);
}

/*
** ф-ия которая определяет в какое место вставить число
*/

char		*ft_add_x(int len, char *str, char *dst, t_data *new)
{
	if (new->fl.sharp != 0 && new->width == 0 && new->prec == 0)
		ft_memlcpy(str, dst, len, 2);
	else if (*dst == '0' && new->dot != 0 && new->prec == 0)
		dst[0] = '-';
	else if (new->width != 0 && new->fl.minus == 0)
		ft_memlcpy(str, dst, len, new->width - len);
	else if (new->prec != 0 && new->fl.sharp == 0)
		ft_memlcpy(str, dst, len, new->prec - len);
	else if (new->prec != 0 && new->fl.sharp != 0)
		ft_memlcpy(str, dst, len, new->prec - len + 2);
	else if (new->width != 0 && new->fl.sharp != 0)
		ft_memlcpy(str, dst, len, 2);
	else
		ft_memlcpy(str, dst, len, 0);
	return (str);
}

/*
** ф-ия которая определяет в какое место вставить ширину
*/

char		*ft_width_x(int len, char *str, t_data *new)
{
	char	*wid;
	char	c;

	c = (new->fl.zero != 0) ? '0' : ' ';
	wid = (char *)malloc(sizeof(char) * new->width + 1);
	wid[new->width] = '\0';
	ft_memset(wid, c, new->width);
	if (new->width > len && new->prec == 0 && new->fl.sharp == 0)
	{
		if (new->fl.minus == 0)
			ft_memlcpy(str, wid, new->width - len, 0);
		else if (new->fl.minus != 0)
			ft_memlcpy(str, wid, new->width - len,
				new->width - (new->width - len));
	}
	if (new->width > len && new->prec == 0 && new->fl.sharp != 0)
	{
		if (new->fl.zero != 0)
			ft_memlcpy(str, wid, new->width - len, 2);
	}
	free(wid);
	return (str);
}

/*
** ф-ия которая определяет в какое место вставить 0x
*/

char		*ft_sharp_x(int len, char *str, t_data *new)
{
	if (new->width != 0 && new->prec == 0 &&
				new->fl.minus == 0 && new->fl.zero == 0)
		ft_memlcpy(str, "0x", 2, new->width - len - 2);
	else if (new->width > new->prec && new->prec != 0 && new->fl.minus == 0)
		ft_memlcpy(str, "0x", 2, new->width - new->prec - 2);
	else
		ft_memlcpy(str, "0x", 2, 0);
	return (str);
}
