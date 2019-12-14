#include "../includes/ft_printf.h"

/*
** 5. Функция подсчитывает длину матиссы
*/

int ft_count_mantissa(f_floats **new)
{
    int i;

    i = 63;
    while ((*new)->mantissa[i] == 0)
        i--;
    return (i);
}

/*
** 4. Функция создает строку из двух int-вых массивов
** a[0] = i, a[1] = j
*/

char *ft_make_str(int *integer_part, int *fractional_part)
{
    int a[2];
    char *x;

    a[0] = 0;
    a[1] = 0;
    x = ft_make_zero_char(1100);
    while (integer_part[a[0]] == 0 && a[0] < 1100)
        a[0]++;
    if (a[0] == 1100)
    {
        a[1]++;
        x[0] = 48;
    }
    while (a[0] < 1100)
        x[a[1]++] = integer_part[a[0]++] + 48;
    x[a[1]] = '.';
    while (fractional_part[a[0]] == 0 && a[0] >= 0)
        a[0]--;
    if (a[0] == -1)
        a[0]++;
    while (a[0] >= 0)
    {
        x[a[0] + a[1] + 1] = fractional_part[a[0]] + 48;
        a[0]--;
    }
    return (x);
}

/*
** 3. Функция собирает дробную часть (правее точки) из порядка, мантиссы
** и эффективного порядка
*/

int *make_fractional(f_floats **new, int *x, int i)
{
    int *temp;
    int *one_arr;
    int *res;

    temp = ft_make_zero_str(1100);
    res = ft_make_zero_str(1100);
    one_arr = ft_make_zero_str(1100);
    one_arr[1099] = 1;
    if ((*new)->mantissa[i] == 1)
    {
        ft_free_new(&temp, ft_exp_long_arithmetic(ft_abs((*new)->ef_order)));
        ft_free_new(&res, ft_division_long_arithmetic(one_arr, temp, 1100, 0));
    }
    else
        free(one_arr);
    ft_free_new(&x, ft_addition_long_arithmetic(x, res, 1100));
    (*new)->ef_order--;
    free(temp);
    free(res);
    return (x);
}

/*
** 2. Функция собирает целую часть (правее точки) из порядка, мантиссы
** и эффективного порядка
*/

int *make_integer(f_floats **new, int *x, int i)
{
    int *temp;

    temp = ft_make_zero_str(1100);
    if ((*new)->mantissa[i] == 1)
        ft_free_new(&temp, ft_exp_long_arithmetic((*new)->ef_order));
    x = ft_addition_long_arithmetic(x, temp, 1100);
    (*new)->ef_order--;
    free(temp);
    return (x);
}

/*
** 1. Функция собирает число изходя из мантиссы и порядка + эффективного порядка
** и возвращает строку result
*/

char *my_number(f_floats **new)
{
    int i;
    char *result;
    int *integer_part;
    int *fractional_part;
    int *temp1;

    i = 0;
    integer_part = ft_make_zero_str(1100);
    fractional_part = ft_make_zero_str(1100);
    result = ft_make_zero_char(1100);
    while (i <= ft_count_mantissa(new))
    {
        if ((*new)->ef_order >= 0)
        {
            temp1 = integer_part;
            integer_part = make_integer(new, integer_part, i);
            free(temp1);
        }
        else
            fractional_part = make_fractional(new, fractional_part, i);
        i++;
    }
    ft_sps_polina(&integer_part, &fractional_part, (*new)->accuracy, i);
   /* i = 0;
    printf("\n округление \n");
    while(i < 50)
    {
        printf("%d", fractional_part[i]);
        i++;
    }*/
    ft_free_result(&result, ft_make_str(integer_part, fractional_part));
    ft_free_array(integer_part, fractional_part);
    return(result);
}





