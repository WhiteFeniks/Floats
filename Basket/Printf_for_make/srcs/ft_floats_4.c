#include "../includes/ft_printf.h"

/*
** 4. Функция для освобождения выделенной памяти int-го массива
*/

void ft_free_result(char **temp1, char *result)
{
    free(*temp1);
    *temp1 = result;
}

/*
** 3. Вспомогательная функция очистки памяти для my_number,
** чтобы уместить в 25 строк
**/

void ft_free_array(int *integer_part, int *fractional_part)
{
    free(integer_part);
    free(fractional_part);
}

/*
** 2. Функция для освобождения выделенной памяти char-ского массива
*/

void ft_free_new(int **temp1, int *result)
{
    free(*temp1);
    *temp1 = result;
}

/*
** 1. Функция создает нулевую строку из char-овских символов
*/

char *ft_make_zero_char(int size)
{
    char *s;
    int i;

    i = 0;
    if (size == 0)
        return(0);
    if (!(s = (char *)malloc(sizeof(char) * size)))
        return (NULL);
    while(i < size)
    {
        s[i] = 0;
        i++;
    }
    return(s);
}