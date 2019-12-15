#include "libft.h"

int *ft_shift_elements_right(int *my_array, int len)
{
    int i;

    i = 1100;
    while (my_array[i] == 0)
        i--;
    while (i >= 0)
    {
        my_array[i + len] = my_array[i];
        if (len != 0)
            my_array[i] = 0;
        i--;
    }
    return(my_array);
}