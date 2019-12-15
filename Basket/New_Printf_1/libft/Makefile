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

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

CFILE = *.c


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
