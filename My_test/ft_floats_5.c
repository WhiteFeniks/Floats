#include "ft_printf.h"

/*
 ** 5. Функция округления дробной части
 */
void ft_round_fract(int **fractional_part, long long int j)
{
    int i;

    i = 0;
    if (fractional_part[i][j] >= 5)
        fractional_part[i][j - 1] += 1;
    while (j > 0)
    {
        while (fractional_part[i][j] == 10)
        {
            fractional_part[i][j - 1] = fractional_part[i][j - 1] + fractional_part[i][j] / 10;
            fractional_part[i][j] = fractional_part[i][j] % 10;
        }
        j--;
    }
}

/*
 ** 4.Функиця округления числа, если точность = 0
 */

void ft_zero_accuracy(int **integer_part, int **fractional_part)
{
    int j;
    int i;

    i = 0;
    j = 1099;
    if (fractional_part[i][0] == 5)
    {
        if (integer_part[i][j] % 2 != 0)
            integer_part[i][j] += 1;
    }
    if (fractional_part[i][0] > 5)
    {
        integer_part[i][j] += 1;
    }
    while (integer_part[i][j] == 10)
    {
        integer_part[i][j - 1] = integer_part[i][j - 1] + integer_part[i][j] / 10;
        integer_part[i][j] = integer_part[i][j] % 10;
        j--;
    }
}

/*
 ** 3. Функция округления числа + функции окргления дробной и целой части
 */

void ft_sps_polina(int **integer_part, int **fractional_part, long long int acc, int i)
{
    long long int j;

    i = 0;
    if (acc == 0)
       ft_zero_accuracy(integer_part, fractional_part);
    j = acc;
    ft_round_fract(fractional_part, j);
    j = 1099;
    while(j > 0)
    {
        if (fractional_part[i][0] == 10)
        {
            if (j == 1099)
            {
                integer_part[i][j] += 1;
                fractional_part[i][0] = 0;
            }
            while (integer_part[i][j] == 10)
            {
                integer_part[i][j - 1] = integer_part[i][j - 1] + integer_part[i][j] / 10;
                integer_part[i][j] = integer_part[i][j] % 10;
                j--;
            }
        }
        j--;
    }
}

/*
 ** 2. Функция проверяющая порядок на наличие чисел != 1 для проверки inf
 */

int check_inf_order(f_floats **new)
{
    int i;

    i = 0;
    while (i < 15)
    {
        if ((*new)->order[i] != 1)
            return (0);
        i++;
    }
    return(1);
}

/*
 ** 1. Функция проверяющая мантиссу на наличие чисел != 0 для проверки inf
 */

int check_inf_mantissa(f_floats **new)
{
    int i;

    i = 0;
    while (i < 65)
    {
        if ((*new)->mantissa[i] != 0)
            return (0);
        i++;
    }
    return(1);
}

