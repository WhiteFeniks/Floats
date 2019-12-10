

#ifndef FLOATS_FLOATS_H
#define FLOATS_FLOATS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct f_struct
{
    char *stroka;
    int order[15];
    int mantissa[64];
    int effective_order;
    int len_stroka;
    int sign;
}               f_floats;

int                 *ft_addition_long_arithmetic(int *x, int *y, int accuracy);
int                 *ft_make_zero_str(int size);
int                 *ft_difference_long_arithmetic(int *x, int *y, int accuracy);
int                 *ft_division_long_arithmetic(int *x, int *y, int accuracy, int numb_of_zero);
int                 *ft_exponentiation_long_arithmetic(int power);
int                 numb_of_zeroes(int *divider);
int                 comparasion(int *x, int *y, int accuracy);

#endif //FLOATS_FLOATS_H
