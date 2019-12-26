/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:05:13 by umoff             #+#    #+#             */
/*   Updated: 2019/12/26 15:48:31 by vaisha           ###   ########.fr       */
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
int						ft_floats(t_data *new);
int						*ft_division_long_arithmetic(int *num, int *div,
						int acc, int numb_of_zero);
int						*ft_exp_long_arithmetic(int squad, int acc);
int						*ft_difference_long_arithmetic(int *a, int *b,
						int acc);
int						*ft_addition_long_arithmetic(int *a, int *b,
						int acc);
int						print_before_dot(int *integer_part,
						int *fract_part, t_data *new);
int						print_after_dot(int *fract_part, t_data *new, int j);
int						ft_make_man(int man[], int order, t_data *new);
int						*ft_division_add_1(int **temp, int **div, int acc);
int						*ft_division_add_2(int **temp, int **div, int acc);
int						*ft_division_add_3(int **num, int **temp, int acc);
int						*ft_division_free(int **num, int *rez);
int						ft_print_nan(t_data *new);
int						ft_print_inf(t_data *new);
int						ft_get_size_f(t_data *new, int j);
void					print_before_dot_addit(int *integer_part,
						int *fract_part, t_data *new, int j);
void					ft_print_after(t_data *new, int len);
void					ft_putchar_dot(t_data *new);

/*
**	ft_dec.c
*/

void					ft_type_conversion_signed(t_sig *sig, t_data *new);
void					ft_print_dec(t_data *new);

/*
**	ft_simple.c
*/

void					ft_print_c(t_data *new);
void					ft_print_s(t_data *new);
void					ft_print_p(t_data *new);
void					ft_print_percent(t_data *new);

/*
**	ft_auxiliary.c
*/

void					ft_leveling(int count, char c, t_data *new);
void					ft_precision(char sign, int len, t_data *new);
char					ft_width(char sign, int len, t_data *new);

/*
**	ft_unsigned.c
*/

void					ft_type_conversion_unsigned(t_uns *uns, t_data *new);
void					ft_print_o(t_data *new);
void					ft_print_u(t_data *new);

/*
**	ft_output.c
*/

void					ft_putstr_precision(char *str, int len, t_data *new);
void					ft_putchar_space(char c, t_data *new);
void					ft_putchar_c(char c, t_data *new);
void					ft_putstr_c(char *s, t_data *new);

/*
**	ft_mutual_exclusion.c
*/

void					ft_mutual_exclusion_prec(int len, t_data *new);
void					ft_mutual_exclusion_width(int len, t_data *new);
void					ft_mutual_exclusion(t_data *new, long long data,
						char c);

/*
**	ft_x_add.c
*/

int						ft_get_size(t_uns *uns, t_data *new);
char					*ft_precision_x(int len, char *str, t_data *new);
char					*ft_sharp_x(int len, char *str, t_data *new);
char					*ft_width_x(int len, char *str, t_data *new);
char					*ft_add_x(int len, char *str, char *dst, t_data *new);

/*
**	ft_x.c
*/

char					*ft_toupper(char *str);
void					ft_formating_x(t_uns *uns, t_data *new);
void					ft_print_x(t_data *new);

/*
**	ft_parcer.c
*/

int						ft_structuring(t_data *new);
void					ft_flags(t_data *new);
int						ft_get_number(t_data *new);
void					ft_get_length(t_data *new);
void					ft_l_or_h(int l, int h, int big_l, t_data *new);

/*
**	ft_printf.c
*/

void					ft_structure_cleaning(t_data *new);
void					ft_determination(t_data *new);
void					ft_start(const char *format, t_data *new);
int						ft_vprintf(const char *format, t_data *new);
int						ft_printf(const char *format, ...);

#endif
