# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/24 18:27:37 by umoff             #+#    #+#              #
#    Updated: 2019/12/26 15:49:55 by vaisha           ###   ########.fr        #
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
		  ft_make_man.c ft_try.c ft_auxiliary.c ft_dec.c ft_printf.c \
		  ft_mutual_exclusion.c ft_output.c ft_parser.c ft_simple.c ft_unsigned.c \
		  ft_x.c ft_x_add.c ft_print_nan_inf.c ft_print_help.c

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
