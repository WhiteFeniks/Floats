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

NAME = libftprintf.a

FLAGS = -g -Wall -Werror -Wextra

FUNCT = *.c


FILE_O = *.o

HEAD = ft_printf.h

$(NAME):
		@gcc -c $(HEAD) $(FUNCT) $(FLAGS)
		@ar -rv $(NAME) $(FILE_O)
		@ranlib $(NAME)
		@./a.out | cat -e

all: $(NAME)

clean:
		@/bin/rm -f *.o

fclean: clean
		@/bin/rm -f $(NAME)
		
re: fclean all
