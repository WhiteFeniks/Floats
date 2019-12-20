#include <unistd.h>
#include <stdio.h>
#include <zconf.h>

union number
{
    long double x;
    short       my_array[5];
};

int make_mantissa(int mantissa[])                               // функция нахождения позиции, где заканчиваются значащие цифры мантиссы
{
    int i;

    i = 63;                                                     // идем с конца
    while (mantissa[i] == 0)                                    // пока элемент мантиссы равен 0
    {
        mantissa[i] = '\0';                                     // ставим \0
        i--;
    }
    return(i);                                                  // возвращаем позицию
}

int power_of_two(int power)                                     // возведение в степень двойку
{
    int result;

    result = 1;
    while(power > 0)                                            // пока степень больше 0
    {
        result = result * 2;                                    // домнажаем result на 2
        power--;                                                // уменьшаем степень
    }
    return (result);                                            // результат = 2^power
}

int make_order(int order[])                                     // идет перевод из двоичной системы порядка в десятичную и вычитание числа 16383 (011 1111 1111 1111), для того чтобы вычислить эффективный порядок
{
    int     i;
    int     k;
    short   digit;

    i = 0;
    k = 14;
    digit = 0;
    while (i < 15)                                              // идем по массиву order
    {
        order[i] = power_of_two(k) * order[i];                  // и на месте каждого умножаем элемент на соотвествующую степень двойки => 2^14 * 0, потом 2^13 * 1, 2^12 * 1, 2^11 * 1 ... 2^0 * 0
        i++;
        k--;
    }
    while (i > 0)                                               // просуммируем все полученные числа в элементах массива
    {
        digit = digit + order[i];
        i--;
    }
    digit = digit - 16383;                                      // 011 1111 1111 1100 - 011 1111 1111 1111 = -3
    return(digit);                                              // эффективный порядок = -3
}


int number_breakdown (char number_of_bits[])
{
    int i;
    int j;
    int k;
    int sign;                                                   // знак
    int order[15];                                              // порядок
    int mantissa[64];                                           // мантисса
    int decimal_order;                                          // порядок в десятичной системе

    sign = number_of_bits[0];                                   // записываем из нулевого элемента массива число в знак
    i = 1;
    j = 0;
    while (i <= 15)                                             // далее с 1 по 15(не включая) идем записываем порядок
        order[j++] = number_of_bits[i++];
    j = 0;
    while (i < 80)                                              // с 16 (включая) по 80 записываем мантиссу
        mantissa[j++] = number_of_bits[i++];
    k = make_mantissa(mantissa);                                // позиция где заканчиваются значащие цифры мантиссы

   /* // // очистить вывод снизу
    i = 0;
    printf("Знак =     %d \n", sign);
    printf("Порядок =  ");
    while(i < 15)
    {
        printf("%d", order[i]);
        i++;
    }
    printf("\n");
    i = 0;
    printf("Мантисса = ");
    while(i <= k)
    {
        printf("%d", mantissa[i]);
        i++;
    }
    printf("\n");
    // очистить ввод сверху */

    decimal_order = make_order(order);                          // перевод порядка в десятичную систему
 /*   // очистить снизу
    printf("Эффективынй порядок = %d", decimal_order);
    // очистить сверху*/
    return(0);
}

int write_number_in_binary(size_t const step, void *my_value)  // функция записи нашего числа из 10-ой системы в двоичную
{
    int             i;
    int             j;
    int             k;                                         // для того чтобы шагать по массиву number_of_bits
    char            number_of_bits[80];                        // как это число записано в памяти компьютера
    unsigned char   *temp;

    i = step - 1;                                              // т.к. начинаем с 0, то чтобы пройти по всему числу нужно step(=10) - 1 раз пройти в цикле
    temp = (unsigned char *) my_value;                         //  наше число записываем в temp
    while (i != -1)
    {
        j = (80 / step) - 1;                                    // long double 80 байт, чтобы все число пройти надо пройти по 8 чисел 10 раз
        while (j != -1)
        {
            number_of_bits[k++] = (temp[i] >> j) & 1;           //переписываем в массив number_of_bits поочередно выделяя по 1 байту (для этого смещаем на j-e количесвто и умножаем на маску 00000001)
            j--;
        }
        i--;
    }
    return (number_breakdown(number_of_bits));                  // получаем как число записано в компьютере
}

int write_number(double num)
{
    int size_array;                                             //размер массива в байтах, необходимо чтобы понять сколько раз нужно зайти в цикл, чтобы получить число 80 (long double).
    union number value;                                         // в нашем случае size_array составляет 10, значит нужно 8 раз зайти в цикл

    value.x = num;                                              // в объединение в поле х записываем наше число
    size_array = sizeof(value.my_array);                        // sizeof - это унарный оператор, возвращающий длину в байтах переменной или типа, помещенных в скобки
    return (write_number_in_binary(size_array, &value.x));      // отправляем наше количество заходов в цикл, и адрес на наше число
}

int main()
{
    write_number(0.15625);                                  // наше приходящее число
}