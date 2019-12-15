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

#include "ft_printf.h"

void		ft_write(t_data *list, char *s)
{
	ft_clean_counts(list);
	while (s && s[list->i])
	{
		write(1, &s[list->i++], 1);
		list->ret++;
	}
}

char change1(char ret)
{
    if (ret == '0')
    {
        ret = '1';
        return (ret);
    }
    if (ret == '1')
    {
        ret = '2';
        return (ret);
    }
    if (ret == '2')
    {
        ret = '3';
        return (ret);
    }
    if (ret == '3')
    {
        ret = '4';
        return (ret);
    }
    if (ret == '4')
    {
        ret = '5';
        return (ret);
    }
    return (ret);
}

char change2(char ret)
{
    if (ret == '5')
    {
        ret = '6';
        return (ret);
    }
    if (ret == '6')
    {
        ret = '7';
        return (ret);
    }
    if (ret == '7')
    {
        ret = '8';
        return (ret);
    }
    if (ret =='8')
    {
        ret = '9';
        return (ret);
    }
    if (ret == '9')
    {
        ret = '0';
        return (ret);
    }
    return (ret);
}

int test_num(char ret)
{
    if ((ret == '5') || (ret == '6') ||  (ret == '7') || (ret == '8') ||  (ret == '9'))
        return (1);
    return (0);
}
char *ft_accuracy_int(char *ret)
{
    int i;
    int k;
    int j;


    j = 0;
    while (ret[j] != '.')
        j++;
    k = j - 1;
    i = j - 1;
    if (i == k)                                     // ecли начальное
    {
        while ((test_num(ret[i]) == 1) && (i >= 0))
            i--;
        while (i <= k)
        {
            if (test_num(ret[i]) == 1)
                ret[i] = change2(ret[i]);
            else
                ret[i] = change1(ret[i]);
            i++;
        }
    }
    return (ret);
}

char *ft_accuracy_fract(char *ret, t_data *list)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    while (ret[j] != '.')
        j++;
    while (i < j + 1 + list->accuracy)
        i++;
    k = i;
    if ((test_num(ret[i]) != 1) && (i == k))  // если начальное число < 5
        return(ret);
    if ((test_num(ret[i]) == 1) && (i == k)) // ecли начальное число >= 5
    {
        while ((test_num(ret[i]) == 1) && (i > j))
            i--;
        while (i < k)
        {
            if (test_num(ret[i]) == 1)
                ret[i] = change2(ret[i]);
            else
                ret[i] = change1(ret[i]);
            i++;
        }
    }
    return (ret);
}

char *ft_rewrite(char *ret, t_data *list)
{
    int i;
    int j;
    char *x;

    i = 0;
    j = 0;
    while (ret[j] != '.')
        j++;
    x = (char *)malloc(sizeof(char) * (list->accuracy + j + 1));
    while(i < list->accuracy + j + 1)
    {
        x[i] = ret[i];
        i++;
    }
    x[i] = '\0';
    return (x);
}

void		ft_f(t_data *list, va_list arg)
{
	double		f;
	char			*ret;

	f = 0;
	ret = NULL;
	f = va_arg(arg, double);
	ret = ft_floats(f);
    ft_accuracy_int(ret);
    ft_accuracy_fract(ret, list);
    ft_rewrite(ret, list);
	ft_write(list, ret);
}

/*
while (((ret[i] == '5') || (ret[i] == '6') ||  (ret[i] == '7') || (ret[i] == '8') ||  (ret[i] == '9')) && (i != -1))
{
ret[i - 1] = change(ret[i - 1]);
i--;
}
*/
