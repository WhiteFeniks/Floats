#include "libft.h"

int ft_abs(int digital)
{
    if (digital < 0)
        digital = (-1) * digital;
    return (digital);
}