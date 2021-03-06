#include <stdio.h>
#include <stdlib.h>

int *ft_make_zero_str(int size)
{
    int *s;                                                                 // создаем строку
    int i;

    i = 0;
    if (size == 0)                                                          // если размер нулевой
        return(0);                                                          // то 0
    if (!(s = (int *)malloc(sizeof(int) * size)))
        return (NULL);                                                      // если строка пустая, то NULL
    while(i < size)                                                         // идем по строке и зануляем ее
    {
        s[i] = 0;
        i++;
    }
    return(s);                                                              // возварщаем int-ую нулевую строку
}

int    *ft_addition_long_arithmetic(int *x, int *y)
{
    int *result;                                                            // результат сложения
    int i;

    i = 1100 - 1;                                                       // начинаем с элемента = длина результата - 1 (последний символ для \0)
    result = ft_make_zero_str(1100);                                    // создание нулевой int-овой строки
    while (i >= 0)                                                          // начинаем с конца (сложение столбиком)
    {
        result[i] = result[i] + x[i] + y[i];                                // складываем поочередно элементы элементы
        if ((result[i] >= 10) && (i != 0))                                  // если получилось число больше 10 и i не нулевой элемент
        {
            result[i - 1] = result[i - 1] + 1;                              // то в следующий символ левее текущего прибавим 1
            result[i] = result[i] % 10;                                     // а в ячейке с i-ым элементом перепишем остаток от деления на 10
        }
        i--;
    }
    return(result);                                                         // выводим результат сложения
}

int main()
{
    int *a;
    int *b;

    a = ft_make_zero_str(1100);
    b = ft_make_zero_str(1100);
    a[1099] = 9;                                                           // 1 число
    a[1098] = 9;
    a[1097] = 9;
    a[1096] = 9;
    a[1095] = 9;
    a[1094] = 9;
    a[1093] = 9;
    a[1092] = 9;

    b[1099] = 1;                                                            // 2 число
    b[1098] = 0;
    b[1097] = 0;
    b[1096] = 0;
    b[1095] = 0;
    b[1094] = 0;
    b[1093] = 0;
    b[1092] = 0;
    int *c;                                                                 // результат сложения
    int acc = 1100;                                                         // точность(количество элементов результата)
    int i = 0;

    c = ft_addition_long_arithmetic (a, b);                                 // запуск функции сложения длинной арифметики
    /* printf("%d", c[1092]); */
    while(c[i] == 0)
        i++;
    while(i < 1100)                                                         // вывод по-символьно полученного результата
    {
        printf("%d", c[i]);
        i++;
    }
    return 0;
}