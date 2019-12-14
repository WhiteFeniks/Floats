#include "../includes/ft_printf.h"

/*
 ** 5. Функция проверки на то, что пришло число 0.0
 ** (Пустые integer_part и fractal_part)
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
 ** 4. Функция возведения в степень power числа 2
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
 ** 3. Функция перевода порядка из 2-ой системы в десятичную и вычитание
 ** числа 16383 (011 1111 1111 1111), чтобы вычислить эффективный порядок
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
	(*new)->ef_order = digit - 16383;
}

/*
 ** 2. Функция нахождения позиции, где заканчиваются значащие цифры мантиссы
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
 ** 1. Функция разбивки числа на мантису, порядок и знак, а так же получение
 ** дробной и целой части, а после перезаписи в строку
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
	}
	else
		(*new)->stroka = my_number(new);
	return((*new)->stroka);
}
