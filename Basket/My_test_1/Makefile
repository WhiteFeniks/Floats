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
#
# # NAME = libftprintf.a
# #
# # FLAGS = -g -Wall -Werror -Wextra
# #
# # FUNCT = *.c
# #
# #
# # FILE_O = *.o
# #
# # HEAD = ft_printf.h
# #
# # $(NAME):
# # 		@gcc -c $(HEAD) $(FUNCT) $(FLAGS)
# # 		@ar -rv $(NAME) $(FILE_O)
# # 		@ranlib $(NAME)
# # 		@./a.out | cat -e
# #
# # all: $(NAME)
# #
# # clean:
# # 		@/bin/rm -f *.o
# #
# # fclean: clean
# # 		@/bin/rm -f $(NAME)
# #
# # re: fclean all
#
# #FLAGS = -Wall -Wextra -Werror
# NAME = ft_printf.c
# #NAME_C = main.c
# NAME_O = $(NAME:.c=.o)
# #RM = /bin/rm -f
#
# #$(NAME):
# #	gcc $(FLAGS) -c $(NAME_C)
# #	gcc $(NAME_O) -L -lft author
#
# all:
# #	gcc -g $(NAME) write_fgr.c -o main.1  -L. libft.a
#
# #	gcc -g $(NAME) -o ft_printf -L. libft/libftprintf.a
# 	gcc -g -L. libft/libft.a *.c
# clean:
# 	$(RM) $(NAME_O)
#
# fclean:clean
# 	$(RM) $(NAME_O)
#
# re: fclean all

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