# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umoff <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 18:43:32 by umoff             #+#    #+#              #
#    Updated: 2019/05/09 14:21:59 by umoff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FLAGS = -Wall -Wextra -Werror
NAME = ft_floats.c
#NAME_C = main.c
NAME_O = $(NAME:.c=.o)
#RM = /bin/rm -f

#$(NAME):
#	gcc $(FLAGS) -c $(NAME_C)
#	gcc $(NAME_O) -L -lft author

all:
#	gcc -g $(NAME) write_fgr.c -o main.1  -L. libft.a

#	gcc -g $(NAME) -o ft_printf -L. libft/libftprintf.a
	gcc -g ft_floats.c -L. libft/libft.a ft_make_zero_str.c \
	ft_addition_long_arithmetic.c ft_difference_long_arithmetic.c \
    ft_division_long_arithmetic.c  ft_division_long_arithmetic_2.c \
    ft_exp_long_arithmetic.c ft_floats_2.c ft_floats_3.c \
    ft_floats_4.c
clean:
	$(RM) $(NAME_O)

fclean:clean
	$(RM) $(NAME_O)

re: fclean all