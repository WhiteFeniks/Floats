

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

#endif //FLOATS_FLOATS_H
