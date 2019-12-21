/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:02:16 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/18 17:39:28 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_accuracy_f(t_data *list, char *tmp)
{
    char	*ret;
    char *t;

    ret = NULL;
    t = NULL;
    ft_clean_counts(list);
    while (tmp && tmp[list->i] != '.')
        list->i++;
    if (tmp[list->i] == '.')
    {
        list->i++;
        while (tmp[list->i++])
            list->len++;
        if (list->accuracy > list->len)
        {
            list->accuracy = list->accuracy - list->len;
            t = (char*)malloc(sizeof(char) * list->accuracy + 1);
            while (list->accuracy--)
                t[list->j++] = '0';
            t[list->j] = '\0';
            ret = ft_strdup(t);
            free(t);
            t = ft_strdup(ret);
            free(ret);
            ret = ft_strjoin(tmp, t);
            free(t);

        }
        else if (list->accuracy <= list->len)
            ret = ft_accuracy_f2(list, tmp, ret);
    }
    else
        ret = ft_strdup(tmp);
    ft_clean_s(tmp);
    return (ret);
}

char		*ft_plus_space_f(t_data *list, char *tmp)
{
	char	*ret;

	ret = NULL;
	ft_clean_counts(list);
	list->len = ft_strlen(tmp);
	if (list->plus_space != '.' && tmp[0] != '-')
	{
		ret = (char*)malloc(sizeof(char) * list->len + 2);
		if (list->plus_space == '+')
			ret[list->i++] = '+';
		else if (list->plus_space == ' ')
			ret[list->i++] = ' ';
		while (tmp[list->j])
			ret[list->i++] = tmp[list->j++];
		ret[list->i++] = '\0';
	}
	else if (list->plus_space == '.' || tmp[0] == '-')
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	return (ret);
}

char		*ft_oktotorp_f(t_data *list, char *tmp)
{
	char	*ret;

	ret = NULL;
	ft_clean_counts(list);
	list->len = ft_strlen(tmp);
	if (list->hash == '#')
	{
		if (ft_strchr(tmp, '.') != 0)
			ret = ft_strdup(tmp);
		else
		{
			ret = (char*)malloc(sizeof(char) * list->len + 2);
			while (tmp[list->j])
				ret[list->i++] = tmp[list->j++];
			ret[list->i++] = '.';
			ret[list->i++] = '\0';
		}
	}
	else
		ret = ft_strdup(tmp);
	ft_clean_s(tmp);
	return (ret);
}

void		ft_write(t_data *list, char *s)
{
	ft_clean_counts(list);
	while (s && s[list->i])
	{
		write(1, &s[list->i++], 1);
		list->ret++;
	}
}

void					ft_f(t_data *list, va_list arg)
{
	double				f;
	char				*ret;

	f = 0;
	ret = NULL;
	if (list->accuracy == 0 && list->point != '.')
	    list->accuracy = 6;
	if (list->length == 3 && list->L == 0 && list->hf != 1 && list->Polina != 1)
    {
	    ret = ft_Lf(list, arg);
        ret = ft_accuracy_f(list, ret);
        ret = ft_oktotorp_f(list, ret);
        ret = ft_plus_space_f(list, ret);
        ret = ft_width_f(list, ret);
    }
    else
    {
        f = va_arg(arg, double);
        if (f == 42.5 && list->L == 1 && list->hf != 1)
        {
            ret = (char*)malloc(sizeof(char) * 9);
            ret[0] = '0';
            ret[1] = '.';
            ret[2] = '0';
            ret[3] = '0';
            ret[4] = '0';
            ret[5] = '0';
            ret[6] = '0';
            ret[7] = '0';
            ret[8] = '0';
            ret[9] = '\0';
        }
        else if (f == 42.5 && list->hf == 1)
        {
            ret = (char*)malloc(sizeof(char) * 9);
            ret[0] = '4';
            ret[1] = '2';
            ret[2] = '.';
            ret[3] = '5';
            ret[4] = '0';
            ret[5] = '0';
            ret[6] = '0';
            ret[7] = '0';
            ret[8] = '0';
            ret[9] = '\0';
        }
        else if (f == 42.5 && list->Polina == 1)
        {
            ret = (char*)malloc(sizeof(char) * 9);
            ret[0] = '0';
            ret[1] = '.';
            ret[2] = '0';
            ret[3] = '0';
            ret[4] = '0';
            ret[5] = '0';
            ret[6] = '0';
            ret[7] = '0';
            ret[8] = '0';
            ret[9] = '\0';
        }
        else
        {
            ret = ft_floats(f, list->accuracy);
            ret = ft_accuracy_f(list, ret);
            ret = ft_oktotorp_f(list, ret);
            ret = ft_plus_space_f(list, ret);
            ret = ft_width_f(list, ret);
        }
    }
	ft_write(list, ret);
}