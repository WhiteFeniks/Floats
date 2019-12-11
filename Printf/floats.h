

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
    int ef_order;
    int sign;
}               f_floats;

int                 *ft_addition_long_arithmetic(int *x, int *y, int accuracy);
int                 *ft_make_zero_str(int size);
int                 *ft_difference_long_arithmetic(int *x, int *y, int accuracy);
int                 *ft_division_long_arithmetic(int *x, int *y, int accuracy, int numb_of_zero);
int                 *ft_exp_long_arithmetic(int power);
int                 numb_of_zeroes(int *divider);
int                 comparasion(int *x, int *y, int accuracy);
char                *number_breakdown (char number_of_bits[], f_floats **new);
char                *my_number(f_floats **new);
char                *ft_make_zero_char(int size);
void                ft_free_array(int *integer_part, int *fractional_part);
void                ft_free_result(char **temp1, char *result);
void                ft_free_new(int **temp1, int *result);

#endif //FLOATS_FLOATS_H
