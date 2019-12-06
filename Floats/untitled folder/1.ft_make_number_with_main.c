#include <stdio.h>
#include "floats.h"


union number                                                                    // объединение, чтобы можно было обратиться к long double
{
    long double x;
    short       my_array[5];                                                    // short занимает 16 байт * 5 = 80 байт (поэтому 5 штук)
};

int shift_one(int len)
{
    int result;

    if (len == 0)
        return (1);
    result = 10;
    while (--len > 0)
        result = result * 10;
    return (result);
}

/*int make_number(int *my_array, f_floats **new)
{
    int i;
    int num;
    int len;
    int count_zero;

    i = 1100;
    num = 0;
    while (my_array[i] == 0)
        i--;
    len = i;
    i = 0;
    (*new)->count_zero = 0;
    while (len >= 0)
    {
        if (my_array[i] == 0)
            (*new)->count_zero++;
        num = num + my_array[i] * shift_one(len);
        len--;
        i++;
    }
    return (num);
}
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

int make_real(double digital)
{
    int result;

    result = 1;
    while (digital > 0)
    {
        result = result * 10;
        digital--;
    }
    return (result);
}

int *ft_shift_in_back(int *result)
{
    int i;
    int j;

    i = 1100;
    while (result[i] == 0 && i >= 0)
        i--;
    j = 1099;
    while (i >= 0)
    {
        result[j] = result[i];
        result[i] = 0;
        i--;
        j--;
    }
    return (result);
}

int *ft_shift_array(int *x)
{
    int i;
    int j;

    i = 0;
    while (x[i] == 0 && i < 1100)
        i++;
    while (i < 1100)
    {
        x[i - 1] = x[i];
        x[i] = 0;
        i++;
    }
    return (x);
}
/*
int multiplication_ten(int len, int *out)
{
    if (len < 0)
    {
        len = (-len);
        while (len >= 0)
        {
            ft_shift_array(out);
            len--;
        }
    }
    return (out);
}
*/
int ft_len(int *array, f_floats **new)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (array[i] == 0)
        i++;
    len = 1100 - i;
    return (len);
}

int ft_count_mantissa(f_floats **new)
{
    int i;
    int count;

    i = 63;
    while ((*new)->mantissa[i] == 0)
        i--;
    return (i);
}

int *make_integer(f_floats **new, int *x, int i)
{
    int *temp;

    temp = ft_make_zero_str(1100);
    if ((*new)->mantissa[i] == 1)
        temp = ft_exponentiation_long_arithmetic((*new)->effective_order);
    x = ft_addition_long_arithmetic(x, temp, 1100);
    (*new)->effective_order--;
    free(temp);
    return (x);
}

int *make_fractional(f_floats **new, int *x, int i)
{
    int *temp;
    int *single_unit_array;
    int *result;

    temp = ft_make_zero_str(1100);
    result = ft_make_zero_str(1100);
    single_unit_array = ft_make_zero_str(1100);
    single_unit_array[1099] = 1;
    if ((*new)->mantissa[i] == 1)
    {
        temp = ft_exponentiation_long_arithmetic(ft_abs((*new)->effective_order));
        result = ft_division_long_arithmetic(single_unit_array, temp, 1100, 0);
    }
    x = ft_addition_long_arithmetic(x, result, 1100);
    (*new)->effective_order--;
    free(temp);
    free(single_unit_array);
    free(result);
    return (x);
}

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

char *ft_make_str(int *integer_part, int *fractional_part)
{
    int i;
    int j;
    char *x;

    i = 0;
    j = 0;
    x = ft_make_zero_char(1100);
    while (integer_part[i] == 0)
        i++;
    while (i < 1100)
        x[j++] = integer_part[i++] + 48;
    x[j] = '.';
    while (fractional_part[i] == 0)
        i--;
    x[i + j + 1] = '\0';
    while (i >= 0)
    {
        x[i + j + 1] = fractional_part[i] + 48;
        i--;
    }


    return (x);
}


char *my_number(f_floats **new)
{
    int i;
    char *result;
    int *integer_part;
    int *fractional_part;

    i = 0;
    integer_part = ft_make_zero_str(1100);
    fractional_part = ft_make_zero_str(1100);
    result = ft_make_zero_char(1100);
    while (i <= ft_count_mantissa(new))
    {
        if ((*new)->effective_order >= 0)
            integer_part = make_integer(new, integer_part, i);
        else
            fractional_part = make_fractional(new, fractional_part, i);
        i++;
    }
    result = ft_make_str(integer_part, fractional_part);

    /* удалить вывод */

    i = 0;
    printf("integer_part = ");
    while (integer_part[i] == 0)
        i++;
    while (i < 1100)
    {
        printf("%d", integer_part[i]);
        i++;
    }
    printf("\n");

    i = 1100;
    int j = 0;
    printf("fractional_part = ");
    while (fractional_part[i] == 0)
        i--;
    while (j <= i)
    {
        printf("%d", fractional_part[j]);
        j++;
    }
    printf("\n ");
    i = 0;
    while (result[i] != '\0')
    {
        printf("%c", result[i]);
        i++;
    }
    return (result);
}
/*
void my_number(f_floats **new)
{
    int i;
    int *single_unit_array;
    int *result;
    int *out;
    int count;

    i = 0;
    count = 0;
    out = ft_make_zero_str(1100);
    ft_count_mantissa(new);
    while(i <= (*new)->count_mantissa)
    {

        result = ft_make_zero_str(1100);
        if ((*new)->effective_order < 0)
        {
            single_unit_array = ft_make_zero_str(1100);
            single_unit_array[1099] = 1;
            result = ft_division_long_arithmetic(single_unit_array, ft_exponentiation_long_arithmetic(i + ft_abs((*new)->effective_order)), 1100, 0);
            result = ft_shift_in_back(result, new);
        }
        count = ((*new)->len_number_2 - (*new)->len_number_1);
        while (count < 0)
        {
            ft_shift_array(out);
            count++;
        }
        if ((*new)->mantissa[i] == 0)
            result = ft_make_zero_str(1100);
        out = ft_addition_long_arithmetic(out, result, 1100);
        (*new)->len_number_2 = ft_len(out, new);
        i++;
    }
    i = 0;
    printf("   ");
    while (out[i] == 0)
        i++;
    while (i < 1100)
    {
        printf("%d", out[i]);
        i++;
    }
}
*/
int make_mantissa(f_floats **new)                                               // функция нахождения позиции, где заканчиваются значащие цифры мантиссы
{
    int i;

    i = 63;                                                                     // идем с конца
    while ((*new)->mantissa[i] == 0)                                            // пока элемент мантиссы равен 0
    {
        (*new)->mantissa[i] = '\0';                                             // ставим \0
        i--;
    }
    return(i);                                                                  // возвращаем позицию
}

int power_of_two(int power)                                                     // возведение в степень двойку
{
    int result;

    result = 1;
    while(power > 0)                                                            // пока степень больше 0
    {
        result = result * 2;                                                    // домножаем result на 2
        power--;                                                                // уменьшаем степень
    }
    return (result);                                                            // результат = 2^power
}

void make_order(f_floats **new)                                                 // идет перевод из двоичной системы порядка в десятичную и вычитание числа 16383 (011 1111 1111 1111),
{                                                                               // для того чтобы вычислить эффективный порядок
    int i;
    int k;
    short digit;

    i = 0;
    k = 14;
    digit = 0;
    while (i < 15)                                                              // идем по массиву order
    {
        (*new)->order[i] = power_of_two(k) * (*new)->order[i];                  // и на месте каждого умножаем элемент на соотвествующую степень двойки => 2^14 * 0, потом 2^13 * 1, 2^12 * 1, 2^11 * 1 ... 2^0 * 0
        i++;
        k--;
    }
    while (--i >= 0)                                                              // просуммируем все полученные числа в элементах массива
        digit = digit + (*new)->order[i];
    (*new)->effective_order = digit - 16383;                                     // 011 1111 1111 1100 - 011 1111 1111 1111 = -3
}                                                                                // эффективный порядок = -3

int number_breakdown (char number_of_bits[], f_floats **new)
{
    int i;
    int j;
    int k;

    (*new)->sign = number_of_bits[0];                                           // записываем из нулевого элемента массива число в знак
    i = 1;
    j = 0;
    while (i <= 15)                                                             // далее с 1 по 15(включая) идем записываем порядок
        (*new)->order[j++] = number_of_bits[i++];
    j = 0;
    while (i < 80)                                                              // с 16 (включая) по 80 записываем мантиссу
        (*new)->mantissa[j++] = number_of_bits[i++];
    k = make_mantissa(new);                                                     // позиция где заканчиваются значащие цифры мантиссы

     // // очистить вывод снизу                                                 // очистить
     i = 0;                                                                     // очистить
     printf("Знак =     %d \n", (*new)->sign);                                  //  очистить
     printf("Порядок =  ");
     while(i < 15)                                                              // очистить
     {
         printf("%d", (*new)->order[i]);
         i++;
     }
     printf("\n");                                                              // очистить
     i = 0;
     printf("Мантисса = ");
     while(i <= k)                                                              // очистить
     {
         printf("%d", (*new)->mantissa[i]);
         i++;                                                                   // очистить
     }
     printf("\n");
     // очистить ввод сверху */                                                 // очистить

    make_order(new);                                                            // перевод порядка в десятичную систему
    // очистить вывод снизу                                                     // очистить
    printf("Эффективынй порядок = %d \n\n", (*new)->effective_order);                // очистить
    // очистить ввод сверху */                                                  // очистить
    my_number(new);
    return(0);
}

int write_number_in_binary(size_t const step, void *my_value, f_floats **new)  // функция записи нашего числа из 10-ой системы в двоичную
{
    int             i;
    int             j;
    int             k;                                                         // для того чтобы шагать по массиву number_of_bits
    char            number_of_bits[80];                                        // как это число записано в памяти компьютера
    unsigned char   *temp;

    i = step - 1;
    k = 0;                                                                      // т.к. начинаем с 0, то чтобы пройти по всему числу нужно step(=10) - 1 раз пройти в цикле
    temp = (unsigned char *) my_value;                                          //  наше число записываем в temp
    while (i != -1)
    {
        j = (80 / step) - 1;                                                    // long double 80 байт, чтобы все число пройти надо пройти по 8 чисел 10 раз
        while (j != -1)
        {
            number_of_bits[k++] = (temp[i] >> j) & 1;                           //переписываем в массив number_of_bits поочередно выделяя по 1 байту (для этого смещаем на j-e количесвто и умножаем на маску 00000001)
            j--;
        }
        i--;
    }
    return (number_breakdown(number_of_bits, new));                             // получаем как число записано в компьютере
}

int write_number(double num, f_floats **new)
{
    int size_array;                                                             //размер массива в байтах, необходимо чтобы понять сколько раз нужно зайти в цикл, чтобы получить число 80 (long double).
    union number value;                                                         // в нашем случае size_array составляет 10, значит нужно 8 раз зайти в цикл

    value.x = num;                                                              // в объединение в поле х записываем наше число
    size_array = sizeof(value.my_array);                                        // sizeof - это унарный оператор, возвращающий длину в байтах переменной или типа, помещенных в скобки
    return (write_number_in_binary(size_array, &value.x, new));                 // отправляем наше количество заходов в цикл, и адрес на наше число
}

int main()
{
    f_floats *new;

    new = (f_floats*)malloc(sizeof(f_floats));                                   // создание структуры с мантисой, порядком, дробной, целой частью и  эффективным порядком
    write_number(1000014583.15132416546549846, &new);                                            // наше приходящее число
    printf("\n %.100f ", 1000014583.15132416546549846  );
}