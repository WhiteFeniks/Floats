#include <stdio.h>
#include "floats.h"

/*
** 4. Функция записи нашего числа из десятичной системы в двоичную
** number_of_bits, как это число записано в памяти компьютера
** i именно такое т.к. начинаем с 0, то чтобы пройти по всему числу нужно
** step(равно 10) - 1 раз пройти в цикле
** наше число записываем в temp
** j такое, т.к. long double 80 байт, чтобы пройти всё число надо пройти
** по 8 чисел 10 раз
** далее в цикле переписываем в массив number_of_bits поочередно выделяя
** по 1 байту
** (для этого смещаем на j-e количество и умножаем на маску 00000001)
** получаем как число записано в компьютере
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
** 3. Объединение, где записано наше число. Т.к long double -> 80
** short -> 16, значит нужно массив из 5 элементов 5*16 = 80
*/

union number
{
    long double x;
    short       my_array[5];
};

/*
** 2. Функция запсивывает полученно значение в поле х, в объединении value
pwd
** нужно зайти в цикл, чтобы получить число 80 (long double)
** в нашем случае size_array составляет 10, значит нужно 8 раз зайти в цикл
** в объединение в поле х записываем наше число
** sizeof - это унарный оператор, возвращающий длину в байтах переменной
** или типа, помещенных в скобки
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

/*
** 1. Основная функция ft_floats
*/

int main()
{
    f_floats *new;

    new = (f_floats*)malloc(sizeof(f_floats));
/*
** Удалить вывод *********************************************************************************
*/
    char *result;
    int i;

    i = 0;
/*
** Удалить вывод *********************************************************************************
*/
    result = write_number(101.0, &new);
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
    i = ft_strlen(result);
    printf("\n%d", i);
/*
**  Удалить вывод *********************************************************************************
*/

    printf("\n%d", printf("\n%.40f", 101.0) - 1);
    free(new->stroka);
    free(new);
}