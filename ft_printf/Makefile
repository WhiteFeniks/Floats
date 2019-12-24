# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umoff <umoff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/24 18:27:37 by umoff             #+#    #+#              #
#    Updated: 2019/12/24 18:27:38 by umoff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -c -Wall -Werror -Wextra

LIBFT = libft

DIR_S = srcs

DIR_O = temporary

HEADER = includes/ft_printf.h

SOURCES = ft_floats.c ft_difference_long_arithmetic.c ft_exp_long_arithmetic.c \
		  ft_division_long_arithmetic.c ft_addition_long_arithmetic.c ft_print.c \
		  ft_make_man.c ft_try.c auxiliary.c dec.c ft_printf.c mutual_exclusion.c \
		  output.c parser.c simple.c unsigned.c x.c x_add.c ft_print_nan_inf.c \
		  ft_print_help.c

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
