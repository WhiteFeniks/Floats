#include <unistd.h>
#include <stdio.h>
#include <zconf.h>

union number
{
    long double x;
    short       my_array[5];
};

int make_mantissa(int mantissa[])
{
    int i;

    i = 63;
    while (mantissa[i] == 0)
    {
        mantissa[i] = '\0';
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

int make_order(int order[])
{
    int     i;
    int     k;
    short   digit;

    i = 0;
    k = 14;
    digit = 0;
    while (i < 15)
    {
        order[i] = power_of_two(k) * order[i];
        i++;
        k--;
    }
    while (i > 0)
    {
        digit = digit + order[i];
        i--;
    }
    digit = digit - 16383;
    return(digit);
}


int number_breakdown (char number_of_bits[])
{
    int i;
    int j;
    int k;
    int sign;
    int order[15];
    int mantissa[64];
    int decimal_order;

    sign = number_of_bits[0];
    i = 1;
    j = 0;
    while (i <= 15)
        order[j++] = number_of_bits[i++];
    j = 0;
    while (i < 80)
        mantissa[j++] = number_of_bits[i++];
    k = make_mantissa(mantissa);
    decimal_order = make_order(order);
    return(0);
}

int write_number_in_binary(size_t const step, void *my_value)
{
    int             i;
    int             j;
    int             k;
    char            number_of_bits[80];
    unsigned char   *temp;

    i = step - 1;
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
    return (number_breakdown(number_of_bits));
}

int write_number(double num)
{
    int size_array;
    union number value;

    value.x = num;
    size_array = sizeof(value.my_array);
    return (write_number_in_binary(size_array, &value.x));
}