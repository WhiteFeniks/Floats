# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umoff <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 18:43:32 by umoff             #+#    #+#              #
#    Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

OBJECTS = *.o

HEADERS = ./

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) -I$(HEADERS) -Wall -Wextra -Werror
	ar -rv $(NAME) $(OBJECTS)
	ranlib $(NAME)
clean:
	/bin/rm -f $(OBJECTS)
fclean: clean	
	/bin/rm -f $(NAME)

re: fclean all  
