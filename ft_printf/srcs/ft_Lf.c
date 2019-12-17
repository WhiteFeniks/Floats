
#include "../includes/ft_printf.h"

void		ft_my_write(t_data *list, char *s)
{
    ft_clean_counts(list);
    while (s && s[list->i])
    {
        write(1, &s[list->i++], 1);
        list->ret++;
    }
}

void		ft_Lf(t_data *list, va_list arg)
{
    long double		Lf;
    char			*ret;

    Lf = 0;
    ret = NULL;
    Lf = va_arg(arg, long double);
    ret = ft_floats(Lf, list->accuracy);
    ft_my_write(list, ret);
}