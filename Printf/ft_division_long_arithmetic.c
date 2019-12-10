#include "floats.h"

/*
 ** Функция подсчёта количества нулей в массиве числа (делителе)
 */

int	numb_of_zeroes(int *divider)
{
    int i;

    i = 0;
    while (divider[i] == 0)
        i++;
    return (i);
}

void ft_free_my(int **temp1, int *result)
{
	free(*temp1);
	*temp1 = result;
}
 /*
 ** Функция сравнения двух массивов
 */

int	comparasion(int *x, int *y, int accuracy)
{
    int i;

    i = 0;
    while (x[i] == 0 && y[i] == 0)
        i++;
    while (x[i] == y[i] && i != accuracy)
        i++;
    if (i == accuracy)
        return (1);
    return ((x[i] > y[i]) ? 1 : 0);
}

 /*
 ** Функция умножения числа на 10
 */

int	*mult_on_ten(int *x, int i, int accuracy)
{
    while (i <= accuracy - 1)
    {
        x[i - 1] = x[i];
        x[i++] = 0;
    }
    return (x);
}

/*
 ** Функция проверки массива на числа отличные от нуля, чтобы в посследствии понять дошли ли мы до конца или нет
 */

int	check_end(int *x, int accuracy)
{
    int i;

    i = 0;
    while (i != accuracy && x[i] == 0)
        i++;
    return (i);
}

int *ft_help(int **x, int **temp, int acc)
{
    int *temp1;
    temp1 = *x;
    *x = ft_difference_long_arithmetic(*x, *temp, acc);
    free(temp1);
    return (*x);
}
/*
 ** Функция деления числа х на у. аccuracy - точность = 1100. Numb_of_zero - количество нулей которые нужно записать
 ** справа от 1, вынесена вверх, чтобы уместить в 25 строк.
 */

int	*ft_division_long_arithmetic(int *x, int *y, int accuracy, int numb_of_zero)
{
    int i;
    int *result;
    int *temp;
   // int *temp1;


    result = ft_make_zero_str(accuracy);
    numb_of_zero = accuracy - 2 - numb_of_zeroes(y);
    x[numb_of_zeroes(y) - 1] = 1;
    x[accuracy - 1] = 0;
    while (++numb_of_zero < accuracy)
    {
        temp = ft_make_zero_str(accuracy);
        while (comparasion(x, temp, accuracy) || --result[numb_of_zero] == 999)
        {
            result[numb_of_zero]++;
            ft_free_my(&temp, ft_addition_long_arithmetic(temp, y, accuracy));
        }
        ft_free_my(&temp, ft_difference_long_arithmetic(temp, y, accuracy));
      //  temp1 = x;
      //  x = ft_difference_long_arithmetic(x, temp, accuracy);
		x = ft_help(&x, &temp, accuracy);
       // free(temp1);
		i = check_end(x, accuracy);
        free(temp);
        if (i == accuracy)
        {
            free(x);
            return (result);
        }
        x = mult_on_ten(x, i, accuracy);
    }
    return (result);
}
