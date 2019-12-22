/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:32:15 by doberyn           #+#    #+#             */
/*   Updated: 2019/11/06 18:19:59 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef	union
{
	long double			i;
	short				c[5];
}						t_un;

typedef struct			s_hex
{
	char				*str;
	int					size;
	int					prlen;
	int					shlen;
}						t_hex;

typedef struct			s_uns
{
	unsigned long long	data;
	char				*str;
	int					len;
	char				sign;
	char				*tmp;
}						t_uns;

typedef struct			s_sig
{
	long long int		data;
	char				*str;
	int					len;
	char				sign;
}						t_sig;

typedef struct			s_flags
{
	int					plus;
	int					sharp:1;
	int					zero:1;
	int					space;
	int					minus:1;
}						t_flags;

typedef struct			s_iterators
{
	int					g;
	int					i;
	int					count;
	int					save;
}						t_iterators;

typedef struct			s_base
{
	const char			*str;
	va_list				arg;
}						t_base;

typedef struct			s_data
{
	int					percent;
	int					width;
	int					dot:1;
	int					prec;
	int					w:1;
	int					length;
	char				type;
	int					sign;
	t_flags				fl;
	t_base				bs;
	t_iterators			it;
}						t_data;

void					ft_putnbr_c(int n, t_data *new);
int						ft_print_float(t_data *new);
int						*ft_long_math_divider(int *num, int *div, int acc,
						int numb_of_zero);
int						*ft_long_math_squad(int squad, int acc);
int						*ft_long_math_substraction(int *a, int *b, int acc);
int						*ft_long_math_summ(int *a, int *b, int acc);
int						print_before_dot(int *rez, t_data *new, int *rez_celoe);
int						print_after_dot(int *rez, t_data *new, int j);
int						make_man(int man[], int por, t_data *new);
int						*ft_first_try(int **temp, int **div, int acc);
int						*ft_second_try(int **temp, int **div, int acc);
int						*ft_third_try(int **num, int **temp, int acc);
int						*ft_trying_four(int **num, int *rez);
int						ft_print_nan(t_data *new);
int						ft_print_inf(t_data *new);
int						ft_get_size_f(t_data *new, int j);
void					print_before_dot_help(int *rez_celoe, t_data *new,
						int *rez, int j);
void					ft_print_after(t_data *new, int len);
void					ft_putchar_1(t_data *new);

/*
**	dec.c - десятичные
** 	fixed	✓
**	norme	✓
*/

void					ft_type_conversion_signed(t_sig *sig, t_data *new);
void					ft_print_dec(t_data *new);

/*
**	simple.c - простые типы
** 	fixed	✓
**	norme	✓
*/

void					ft_print_c(t_data *new);
void					ft_print_s(t_data *new);
void					ft_print_p(t_data *new);
void					ft_print_percent(t_data *new);

/*
**	auxiliary.c - вспомогательные
** 	fixed	✓
**	norme	✓
*/

void					ft_leveling(int count, char c, t_data *new);
void					ft_precision(char sign, int len, t_data *new);
char					ft_width(char sign, int len, t_data *new);

/*
**	unsigned.c - беззнаковые
** 	fixed	✓
**	norme	✓
*/

void					ft_type_conversion_unsigned(t_uns *uns, t_data *new);
void					ft_print_o(t_data *new);
void					ft_print_u(t_data *new);

/*
**	unsigned.c - безнаковые
** 	fixed	✓
**	norme	✓
*/

void					ft_type_conversion_unsigned(t_uns *uns, t_data *new);
void					ft_print_o(t_data *new);
void					ft_print_u(t_data *new);

/*
**	output.c - вывод
** 	fixed	✓
**	norme	✓
*/

void					ft_putstr_precision(char *str, int len, t_data *new);
void					ft_putchar_space(char c, t_data *new);
void					ft_putchar_c(char c, t_data *new);
void					ft_putstr_c(char *s, t_data *new);

/*
**	mutual_exclusion.c - взаимоисключения
** 	fixed	✓
**	norme	✓
*/

void					ft_mutual_exclusion_prec(int len, t_data *new);
void					ft_mutual_exclusion_width(int len, t_data *new);
void					ft_mutual_exclusion(t_data *new, long long data,
						char c);

/*
**	x_add.c
** 	fixed	✓
**	norme
*/

int						ft_get_size(t_uns *uns, t_data *new);
char					*ft_precision_x(int len, char *str, t_data *new);
char					*ft_sharp_x(int len, char *str, t_data *new);
char					*ft_width_x(int len, char *str, t_data *new);
char					*ft_add_x(int len, char *str, char *dst, t_data *new);

/*
**	x.c
** 	fixed	✓
**	norme	✓
*/

char					*ft_toupper(char *str);
void					ft_formating_x(t_uns *uns, t_data *new);
void					ft_print_x(t_data *new);

/*
**	parcer.c
** 	fixed	✓
**	norme	✓
*/

int						ft_structuring(t_data *new);
void					ft_flags(t_data *new);
int						ft_get_number(t_data *new);
void					ft_get_length(t_data *new);
void					ft_l_or_h(int l, int h, int big_l, t_data *new);

/*
**	ft_printf.c
** 	fixed	✓
**	norme	✓
*/

void					ft_structure_cleaning(t_data *new);
void					ft_determination(t_data *new);
void					ft_start(const char *format, t_data *new);
int						ft_vprintf(const char *format, t_data *new);
int						ft_printf(const char *format, ...);

#endif
