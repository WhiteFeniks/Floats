# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umoff <umoff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/27 13:53:20 by umoff             #+#    #+#              #
#    Updated: 2019/12/27 13:53:23 by umoff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

CFILE = ft_memchr.c \
		ft_strlen.c \
		ft_isdigit.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strjoin.c \
        ft_itoa_base_sig.c \
        ft_itoa_base_unsig.c \
        ft_memset.c \
        ft_memlcpy.c \
        ft_make_zero_str.c \
        ft_intlen.c


OFILE = $(CFILE:.c=.o)

all: $(NAME)

$(NAME): $(OFILE)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

clean:
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all