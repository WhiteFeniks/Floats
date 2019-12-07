#include <stdio.h>
#include "floats.h"


union number
{
    long double x;
    short       my_array[5];
};


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


int ft_count_mantissa(f_floats **new)
{
    int i;

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
	{
		int *tmp1;
		tmp1 = ft_exponentiation_long_arithmetic((*new)->effective_order);
		//temp = ft_exponentiation_long_arithmetic((*new)->effective_order);
		free(temp);
		temp = NULL;
		temp = tmp1;
	}
    int *tmp;
    tmp = ft_addition_long_arithmetic(x, temp, 1100);
//  x = ft_addition_long_arithmetic(x, temp, 1100);
    free(x);
    x = NULL;
    x = tmp;
    printf("new x = %d\n", *x);
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
		int *tmp2 = NULL;
		tmp2 = ft_exponentiation_long_arithmetic(ft_abs((*new)->effective_order));
		//   temp = ft_exponentiation_long_arithmetic(ft_abs((*new)->effective_order));
		free(temp);
		temp = NULL;
		temp = tmp2;
    	//   temp = ft_exponentiation_long_arithmetic(ft_abs((*new)->effective_order));
		int *tmp1 = NULL;
		tmp1 = ft_division_long_arithmetic(single_unit_array, temp, 1100, 0);
       // result = ft_division_long_arithmetic(single_unit_array, temp, 1100, 0);
		free(result);
		result = NULL;
		result = tmp1;
		//free(temp);
    }
  //  free(temp);
    int *tmp = NULL;
    tmp = ft_addition_long_arithmetic(x, result, 1100);
//    x = ft_addition_long_arithmetic(x, result, 1100);
    free(x);
    x = NULL;
    x = tmp;
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


char    *my_number(f_floats **new)
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
	char *tmp = NULL;
	tmp = ft_make_str(integer_part, fractional_part);
	//   result = ft_make_str(integer_part, fractional_part);
	free(result);
	result = NULL;
	result = tmp;

    (*new)->len_stroka = ft_strlen(result);
    free(integer_part);
    free(fractional_part);
  //  free(result);

    /*
*  Удалить вывод *********************************************************************************
*/

   /* i = 0;
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
    }*/
    printf("\n");
    i = 0;
    while (result[i] != '\0')
    {
        printf("%c", result[i]);
        i++;
    }
    //free(result);
    return (result);
/*
 *  Удалить вывод *********************************************************************************
 */
}

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

int number_breakdown (char number_of_bits[], f_floats **new)
{
    int i;
    int j;
    int k;

    (*new)->sign = number_of_bits[0];
    i = 1;
    j = 0;
    while (i <= 15)
        (*new)->order[j++] = number_of_bits[i++];
    j = 0;
    while (i < 80)
        (*new)->mantissa[j++] = number_of_bits[i++];
    k = make_mantissa(new);
    make_order(new);
   // my_number(new);
    (*new)->stroka = my_number(new);
    free((*new)->stroka);
    return(0);
}

int write_number_in_binary(size_t const step, void *my_value, f_floats **new)
{
    int             i;
    int             j;
    int             k;
    char            number_of_bits[80];
    unsigned char   *temp;

    i = step - 1;
    k = 0;
    temp = (unsigned char *) my_value;
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

int write_number(double num, f_floats **new)
{
    int size_array;
    union number value;

    value.x = num;
    size_array = sizeof(value.my_array);
    return (write_number_in_binary(size_array, &value.x, new));
}

/*void free_f_floats(f_floats **new)
{

}*/

int main()
{
    f_floats *new;

    new = (f_floats*)malloc(sizeof(f_floats));
    write_number(1000014583.0000001225331212214755542, &new);
    printf("\n%d", new->len_stroka);
    printf("\n%d", printf("\n%.23f", 1000014583.0000001225331212214755542) - 1);
//	free((new)->stroka);
    free(new);
}