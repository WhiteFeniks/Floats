#include <stdio.h>
#include "floats.h"

/*
** Объединение где записано наше число
*/

union number
{
    long double x;
    short       my_array[5];
};

/*
** Функция для освобождения выделенной памяти
*/

void ft_free_new(int **temp1, int *result)
{
	free(*temp1);
	*temp1 = result;
}

/*
** Функция подсчитывает длину числа
*/

int len_number(int digital)
{
    int len;

    len = 0;
    while (digital % 10 != 0)
    {
        digital = digital / 10;
        len++;
    }
    return (len);
}

/*
** Функция подсчитывает длину матиссы
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
** Функция собирает целую часть (правее точки) из порядка, мантиссы и эффективного порядка
*/

int *make_integer(f_floats **new, int *x, int i)
{
    int *temp;

    temp = ft_make_zero_str(1100);
    if ((*new)->mantissa[i] == 1)
        ft_free_new(&temp, ft_exponentiation_long_arithmetic((*new)->effective_order));
    x = ft_addition_long_arithmetic(x, temp, 1100);
    (*new)->effective_order--;
    free(temp);
    return (x);
}

/*
** Функция собирает дробную часть (правее точки) из порядка, мантиссы и эффективного порядка
*/

int *make_fractional(f_floats **new, int *x, int i)
{
    int *temp;
    int *single_unit_array;
    int *result;
 //   int *temp1;

    temp = ft_make_zero_str(1100);
    result = ft_make_zero_str(1100);
    single_unit_array = ft_make_zero_str(1100);
    single_unit_array[1099] = 1;
    if ((*new)->mantissa[i] == 1)
    {
        ft_free_new(&temp, ft_exponentiation_long_arithmetic(ft_abs((*new)->effective_order)));
        //temp1 =result;
       // result = ft_division_long_arithmetic(single_unit_array, temp, 1100, 0);
        ft_free_new(&result, ft_division_long_arithmetic(single_unit_array, temp, 1100, 0));
       // free(temp1);
    }
    else
        free(single_unit_array);
    ft_free_new(&x, ft_addition_long_arithmetic(x, result, 1100));
    (*new)->effective_order--;
    free(temp);
    free(result);
    return (x);
}


/*
** Функция создает нулевую строку из char-овских символов
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

/*
** Функция создает строку из двух int-вых массивов
*/

char *ft_make_str(int *integer_part, int *fractional_part)
{
 //   int a[0];
  //  int a[1];
    int a[2];  // a[0] = i, a[1] = j
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
   // x[i + j + 1] = '\0';
    while (a[0] >= 0)
    {
        x[a[0] + a[1] + 1] = fractional_part[a[0]] + 48;
        a[0]--;
    }
    return (x);
}

/*
** Вспомогательная функция для my_number, чтобы уместить в 25 строк
**/

void ft_free_array(char *temp2, int *integer_part, int *fractional_part)
{
    free(temp2);
    free(integer_part);
    free(fractional_part);
}

/*
** Функция собирает число изходя из мантиссы и порядка + эффективного порядка
*/

char *my_number(f_floats **new)
{
    int i;
    char *result;
    int *integer_part;
    int *fractional_part;
    int *temp1;
    char *temp2;

    i = 0;
    integer_part = ft_make_zero_str(1100);
    fractional_part = ft_make_zero_str(1100);
    result = ft_make_zero_char(1100);
    while (i <= ft_count_mantissa(new))
    {
        if ((*new)->effective_order >= 0)
		{
        	temp1 = integer_part;
			integer_part = make_integer(new, integer_part, i);
			free(temp1);
		}
        else
			fractional_part = make_fractional(new, fractional_part, i);
        i++;
    }
    temp2 = result;
    result = ft_make_str(integer_part, fractional_part);
    ft_free_array(temp2, integer_part, fractional_part);
    // free(temp2);
    // free(integer_part);
    // free(fractional_part);
/*
** Удалить вывод *********************************************************************************
*/
    printf("\n");
    int j = 0;
    i = 1100;
    while (result[i] == 0)
        i--;
    while (j <= i)
    {
        printf("%c", result[j]);
        j++;
    }
/*
**  Удалить вывод *********************************************************************************
*/
    return(result);
}

/*
** Функция нахождения позиции, где заканчиваются значащие цифры мантиссы
*/

int make_mantissa(f_floats **new)
{
    int i;

    i = 63;
    while ((*new)->mantissa[i] == 0)
    {
        (*new)->mantissa[i] = '\0';
        i--;
    }
    return(i);
}

/*
** Функция возведения в степень 2 (двойки)
*/

int power_of_two(int power)
{
    int result;

    result = 1;
    while(power > 0)
    {
        result = result * 2;
        power--;
    }
    return (result);
}

/*
** Идет перевод из двоичной системы порядка в десятичную и вычитание числа 16383 (011 1111 1111 1111),
** для того чтобы вычислить эффективный порядок
*/

void make_order(f_floats **new)
{
    int i;
    int k;
    short digit;

    i = 0;
    k = 14;
    digit = 0;
    while (i < 15)
    {
        (*new)->order[i] = power_of_two(k) * (*new)->order[i];
        i++;
        k--;
    }
    while (--i >= 0)
        digit = digit + (*new)->order[i];
    (*new)->effective_order = digit - 16383;
}

/*
** Функция проверки на то, что пришло число 0.0 (Пустые integer_part и fractal_part)
*/

int check_zero(f_floats **new)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while ((*new)->order[i] == 0 && i <= 14)
        i++;
    while ((*new)->mantissa[j] == 0 && j <= 63)
        j++;
    if (i + j == 79)
        return (0);
    return (1);
}


/*
** Функция разбивки числа на мантису, порядок и знак, а так же получение дробной и целой части,
** а после перезаписи в строку
*/

char *number_breakdown (char number_of_bits[], f_floats **new)
{
    int i;
    int j;

    (*new)->sign = number_of_bits[0];
    i = 1;
    j = 0;
    while (i <= 15)
        (*new)->order[j++] = number_of_bits[i++];
    j = 0;
    while (i < 80)
        (*new)->mantissa[j++] = number_of_bits[i++];
    make_mantissa(new);
    make_order(new);
    if (check_zero(new) == 0)
    {
        (*new)->stroka = ft_make_zero_char(1100);
        (*new)->stroka[0] = '0';
        (*new)->stroka[1] = '.';
        (*new)->stroka[2] = '0';
/*
** Удалить вывод *******************************************************************************
*/
        printf("%s", (*new)->stroka);
/*
** Удалить вывод *******************************************************************************
*/
    }
    else
        (*new)->stroka = my_number(new);
/*
** Удалить вывод *******************************************************************************
*/
    (*new)->len_stroka = ft_strlen((*new)->stroka);
/*
** Удалить вывод *******************************************************************************
*/
	return((*new)->stroka);
}

/*
** Функция записи нашего числа из 10-ой системы в двоичную
*/

char     *write_number_in_binary(size_t const step, void *value, f_floats **new)
{
    int             i;
    int             j;
    int             k;
    char            number_of_bits[80];
    unsigned char   *temp;

    i = step - 1;
    k = 0;
    temp = (unsigned char *) value;
    while (i != -1)
    {
        j = (80 / step) - 1;
        while (j != -1)
        {
            number_of_bits[k++] = (temp[i] >> j) & 1;
            j--;
        }
        i--;
    }
    return (number_breakdown(number_of_bits, new));
}
/*
** Sixe_array - Размер массива в байтах, необходимо чтобы понять сколько раз нужно зайти в цикл, чтобы получить число 80 (long double)
** в нашем случае size_array составляет 10, значит нужно 8 раз зайти в цикл
** в объединение в поле х записываем наше число
** sizeof - это унарный оператор, возвращающий длину в байтах переменной или типа, помещенных в скобки
** отправляем наше количество заходов в цикл, и адрес на наше число
*/
char     *write_number(double num, f_floats **new)
{
    int size_array;
    union number value;

    value.x = num;
    size_array = sizeof(value.my_array);
    return (write_number_in_binary(size_array, &value.x, new));
}

int main()
{
    f_floats *new;

    new = (f_floats*)malloc(sizeof(f_floats));
    write_number(45645646545.7, &new);

    printf("\n%d", new->len_stroka);
    printf("\n%d", printf("\n%.40f", 45645646545.7) - 1);
    free(new->stroka);
    free(new);
}