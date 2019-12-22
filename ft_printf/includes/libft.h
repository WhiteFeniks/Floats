/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:30:37 by doberyn           #+#    #+#             */
/*   Updated: 2019/04/20 00:15:06 by doberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memlcpy(void *dst, const void *src, size_t n, int pos);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa_base_sig(long long value, int base);
char				*ft_itoa_base_unsig(unsigned long long value, int base);
int					ft_isdigit(int c);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				*ft_memchr(const void *s, int c, size_t n);
int					*ft_intstr(int size);
size_t				ft_intlen(long long data);

#endif
