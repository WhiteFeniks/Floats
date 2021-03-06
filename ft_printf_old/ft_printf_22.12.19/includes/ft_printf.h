/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:50:51 by vaisha            #+#    #+#             */
/*   Updated: 2019/12/22 00:03:23 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../includes/libft.h"

/*
** 3. Объединение, где записано наше число. Т.к long double -> 80
** short -> 16, значит нужно массив из 5 элементов 5*16 = 80
*/

typedef	union
{
	long double				x;
	short					my_array[5];
}							t_un;

/*
** 1 = l;2 = h;3 = L;4 = ll;5 = hh;
*/

typedef struct				s_data
{
	char					percent;
	char					plus_space;
	char					minus_null;
	char					hash;
	char					point;
	char					type;
	long long int			width;
	long long int			accuracy;
	int						length;
	long long int			ret;
	long long int			len;
	long long int			i;
	long long int			j;
	long long int			tmp;
	int						nol;
	int						hf;
	int						l;
	int						polina;
	int						res;
}							t_data;

typedef struct				s_struct
{
	char					*stroka;
	int						order[15];
	int						mantissa[64];
	int						ef_order;
	int						sign;
	long long int			accuracy;
	long long				i;
	long long				j;
}							t_floats;

int							main();
int							ft_printf(const char *format, ...);
int							rem_width_accuracy(const char *format, va_list arg,
							int i, t_data *list);
int							rem_length(const char *format, int i, t_data *list);
int							ft_take_digit(const char *format, int i,
							t_data *list);
int							ft_l(const char *format, int i, t_data *list);
int							ft_h(const char *format, int i, t_data *list);
int							ft_procent(t_data *list, int i);
int							ft_precent(const char *format, va_list arg,
							t_data *list, int i);
void						ft_allocation(t_data *list, va_list arg);
void						rem_type(const char *format, int i, t_data *list);
void						rem_flag(const char *format, int i, t_data *list);
void						ft_f(t_data *list, va_list arg);
void						ft_c(t_data *list, va_list arg);
void						ft_d_i(t_data *list, va_list arg);
void						ft_o(t_data *list, va_list arg);
void						ft_p(t_data *list, va_list arg);
void						ft_s(t_data *list, va_list arg);
void						ft_u(t_data *list, va_list arg);
void						ft_x(t_data *list, va_list arg);
void						ft_before(t_data *list, char *s, char *str);
void						ft_width_s(t_data *list);
void						ft_write_and_clean_s(t_data *list, char *s);
void						ft_only_width(t_data *list, char *s, char *str);
void						ft_width_d(t_data *list, char *tmp);
void						ft_clean_counts(t_data *list);
void						ft_clean_list(t_data *list);
void						ft_clean_all(t_data *list);
void						ft_clean_s(char *s);
void						ft_null(t_data *list, char *str);
char						*ft_accuracy_o(t_data *list, char *tmp, char *ret);
void						ft_null_s(t_data *list, char *str);
void						ft_width_null_s(t_data *list, char *str, char *tmp);
int							ft_help_i(t_data *list, int value);
void						ft_list_null(t_data *list, char *s, char *str);
void						ft_list_null2(t_data *list, char *s, char *str);
void						ft_list_null3(t_data *list, char *s, char *str);
int							*ft_addition_long_arithmetic(int *x,
							int *y, int accuracy);
int							*ft_difference_long_arithmetic(int *x,
							int *y, int accuracy);
int							*ft_exp_long_arithmetic(int power);
int							*ft_division_long_arithmetic(int *x, int *y,
							int accuracy, int numb_of_zero);
int							comparasion(int *x, int *y, int accuracy);
int							numb_of_zeroes(int *divider);
int							*ft_make_zero_str(int size);
char						*ft_floats(double num, long long int accuracy);
char						*ft_lf_floats(long double num,
							long long int accuracy);
char						*number_breakdown (char number_of_bits[],
							t_floats **new);
char						*my_number(t_floats **new);
char						*ft_make_zero_char(int size);
void						ft_free_array(int *integer_part,
							int *fractional_part);
void						ft_free_result(char **temp1, char *result);
void						ft_free_new(int **temp1, int *result);
void						ft_sps_polina(int **int_part, int **fract_part,
							long long int acc, int i);
int							check_inf_order(t_floats **new);
int							check_inf_mantissa(t_floats **new);
char						*make_inf(t_floats **new);
char						*ft_width_f(t_data *list, char *tmp);
char						*ft_accuracy_f2(t_data *list, char *tmp, char *ret);
char						*ft_lf(t_data *list, va_list arg);
void						ft_f_help(va_list arg, t_data *list, double f,
							char *ret);
void						ft_write(t_data *list, char *s);
char						*ft_accuracy_f(t_data *list, char *tmp);
char						*ft_oktotorp_f(t_data *list, char *tmp);
char						*ft_plus_space_f(t_data *list, char *tmp);
void						ft_u_help(t_data *list, char *str, long long u);
char						*ft_conversion_u(long long int value, int base);
char						*ft_accuracy_u(t_data *list, char *tmp);

#endif
