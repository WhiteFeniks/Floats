cmake_minimum_required(VERSION 3.15)
project(Floats C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories("untitled folder")
include_directories("untitled folder/libft")

add_executable(Floats
        "untitled folder/libft/ft_abs.c"
        "untitled folder/libft/ft_addition_long_arithmetic.c"
        "untitled folder/libft/ft_atoi.c"
        "untitled folder/libft/ft_bzero.c"
        "untitled folder/libft/ft_difference_long_arithmetic.c"
        "untitled folder/libft/ft_division_long_arithmetic.c"
        "untitled folder/libft/ft_exponentiation_long_arithmetic.c"
        "untitled folder/libft/ft_isalnum.c"
        "untitled folder/libft/ft_isalpha.c"
        "untitled folder/libft/ft_isascii.c"
        "untitled folder/libft/ft_isdigit.c"
        "untitled folder/libft/ft_isprint.c"
        "untitled folder/libft/ft_isspace.c"
        "untitled folder/libft/ft_itoa.c"
        "untitled folder/libft/ft_lstadd.c"
        "untitled folder/libft/ft_lstdel.c"
        "untitled folder/libft/ft_lstdelone.c"
        "untitled folder/libft/ft_lstiter.c"
        "untitled folder/libft/ft_lstmap.c"
        "untitled folder/libft/ft_lstnew.c"
        "untitled folder/libft/ft_make_zero_str.c"
        "untitled folder/libft/ft_memalloc.c"
        "untitled folder/libft/ft_memccpy.c"
        "untitled folder/libft/ft_memchr.c"
        "untitled folder/libft/ft_memcmp.c"
        "untitled folder/libft/ft_memcpy.c"
        "untitled folder/libft/ft_memdel.c"
        "untitled folder/libft/ft_memmove.c"
        "untitled folder/libft/ft_memset.c"
        "untitled folder/libft/ft_putchar.c"
        "untitled folder/libft/ft_putchar_fd.c"
        "untitled folder/libft/ft_putendl.c"
        "untitled folder/libft/ft_putendl_fd.c"
        "untitled folder/libft/ft_putnbr.c"
        "untitled folder/libft/ft_putnbr_fd.c"
        "untitled folder/libft/ft_putstr.c"
        "untitled folder/libft/ft_putstr_fd.c"
        "untitled folder/libft/ft_shift_elements_left.c"
        "untitled folder/libft/ft_shift_elements_right.c"
        "untitled folder/libft/ft_strcat.c"
        "untitled folder/libft/ft_strchr.c"
        "untitled folder/libft/ft_strclr.c"
        "untitled folder/libft/ft_strcmp.c"
        "untitled folder/libft/ft_strcpy.c"
        "untitled folder/libft/ft_strdel.c"
        "untitled folder/libft/ft_strdup.c"
        "untitled folder/libft/ft_strequ.c"
        "untitled folder/libft/ft_striter.c"
        "untitled folder/libft/ft_striteri.c"
        "untitled folder/libft/ft_strjoin.c"
        "untitled folder/libft/ft_strlcat.c"
        "untitled folder/libft/ft_strlen.c"
        "untitled folder/libft/ft_strmap.c"
        "untitled folder/libft/ft_strmapi.c"
        "untitled folder/libft/ft_strncat.c"
        "untitled folder/libft/ft_strncmp.c"
        "untitled folder/libft/ft_strncpy.c"
        "untitled folder/libft/ft_strndup.c"
        "untitled folder/libft/ft_strnequ.c"
        "untitled folder/libft/ft_strnew.c"
        "untitled folder/libft/ft_strnstr.c"
        "untitled folder/libft/ft_strrchr.c"
        "untitled folder/libft/ft_strsplit.c"
        "untitled folder/libft/ft_strstr.c"
        "untitled folder/libft/ft_strsub.c"
        "untitled folder/libft/ft_strtrim.c"
        "untitled folder/libft/ft_tolower.c"
        "untitled folder/libft/ft_toupper.c"
        "untitled folder/libft/libft.h"
        "untitled folder/1.ft_make_number_with_main.c"
        "untitled folder/floats.h"
        1.ft_abs_with_main.c
        1.ft_addition_long_arithmetic_with_main.c
        1.ft_array_comparison_with_main.c
        1.ft_difference_long_arithmetic_with_main.c
        1.ft_division_long_arithmetic_with_main.c
        1.ft_exponentiation_long_arithmetic_with_main.c
        1.ft_make_number_with_main.c
        1.ft_make_zero_str_with_main.c
        1.ft_shift_elements_with_main.c
        floats.c
        floats.h
        ft_abs.c
        ft_addition_long_arithmetic.c
        ft_array_comparison.c
        ft_difference_long_arithmetic.c
        ft_division_long_arithmetic.c
        ft_exponentiation_long_arithmetic.c
        ft_make_number.c
        ft_make_zero_str.c
        ft_shift_elements.c)
