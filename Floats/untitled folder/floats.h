

#ifndef FLOATS_FLOATS_H
#define FLOATS_FLOATS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct f_struct
{
    int sign;
    int integer_part[1100];
    int fractional_part[1100];
    int order[15];
    int mantissa[64];
    int effective_order;
    int count_zero;
    int len_number_1;
    int len_number_2;
}               f_floats;

#endif //FLOATS_FLOATS_H
