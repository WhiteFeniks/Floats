
#include "ft_printf.h"

char		*ft_Lf(t_data *list, va_list arg)
{
    long double		Lf;
    char			*ret;

    Lf = 0;
    ret = NULL;
    Lf = va_arg(arg, long double);
    ret = ft_floats(Lf, list->accuracy);
    return (ret);
}


