# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 21:47:45 by msabre            #+#    #+#              #
#    Updated: 2019/12/21 22:05:38 by vaisha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = libftprintf.a

FLAGS = -c -Wall -Werror -Wextra

LIBFT = libft

DIR_S = srcs

DIR_O = temporary

HEADER = includes/ft_printf.h

SOURCES = ft_addition_long_arithmetic.c ft_allocation.c ft_c.c ft_d_i.c \
ft_difference_long_arithmetic.c ft_division_long_arithmetic_2.c \
ft_division_long_arithmetic.c ft_exp_long_arithmetic.c \
ft_f.c ft_floats_2.c ft_floats_3.c ft_floats_4.c ft_floats_5.c \
ft_floats.c ft_help_s.c ft_help_s2.c ft_make_zero_str.c \
ft_null_s.c ft_null.c ft_o.c ft_p.c ft_percent.c ft_printf.c \
ft_remember.c ft_s.c ft_take_digit.c ft_u.c ft_widht_d.c \
ft_write_and_clean.c ft_x.c ft_lf.c ft_width_f.c ft_lf_floats.c \
ft_hhhhhhelp.c

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "ok"

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
	@echo "deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
