#include "../includes/ft_printf.h"

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

