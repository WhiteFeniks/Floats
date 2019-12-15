# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 14:21:49 by vaisha            #+#    #+#              #
#    Updated: 2019/12/06 15:36:59 by vaisha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -c -Wall -Werror -Wextra

LIBFT = libft

DIR_S = srcs

DIR_O = temporary

HEADER = includes/ft_printf.h

SOURCES = *.c

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	//@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all