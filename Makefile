# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aazri <aazri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 17:35:54 by aazri             #+#    #+#              #
#    Updated: 2017/03/20 17:50:15 by aazri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
INCLUDE = -Ilibft -Iinclude
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)
LIB_PATH = ./libft/
SRC_PATH = ./src/
RM = rm -f

SRC =	$(SRC_PATH)ft_printf.c \
		$(SRC_PATH)handle_char.c \
		$(SRC_PATH)handle_decimal.c \
		$(SRC_PATH)handle_hexadecimal.c \
		$(SRC_PATH)handle_octal.c \
		$(SRC_PATH)handle_string.c \
		$(SRC_PATH)length_specifier.c \
		$(SRC_PATH)parsing_flags.c \
		$(SRC_PATH)utils.c \
		$(SRC_PATH)utils_wchar.c \
		$(SRC_PATH)get_func_array.c \
		$(SRC_PATH)get_str_to_print.c \
		$(SRC_PATH)hex_pad.c \
		$(SRC_PATH)decimal_pad.c \
		$(SRC_PATH)print_count.c \

OBJ_LIB =	$(LIB_PATH)ft_strlen.o \
			$(LIB_PATH)ft_putstr.o \
			$(LIB_PATH)ft_toupper.o \
			$(LIB_PATH)ft_putchar.o \
			$(LIB_PATH)ft_bzero.o \
			$(LIB_PATH)ft_strtolower.o \
			$(LIB_PATH)ft_strjoin.o \
			$(LIB_PATH)ft_atoi.o \
			$(LIB_PATH)ft_isdigit.o \
			$(LIB_PATH)ft_itoa_base.o \
			$(LIB_PATH)ft_utoa_base.o \
			$(LIB_PATH)ft_isascii.o \
			$(LIB_PATH)ft_strcpy.o \
			$(LIB_PATH)ft_strcat.o \
			$(LIB_PATH)ft_strndup.o \
			$(LIB_PATH)ft_strdup.o \
			$(LIB_PATH)ft_putnstr.o \
			$(LIB_PATH)ft_strncpy.o \
			$(LIB_PATH)ft_memset.o \
			$(LIB_PATH)ft_memalloc.o \

OBJ_SRC = $(SRC:.c=.o)

$(NAME): $(OBJ_SRC)
	@make -C $(LIB_PATH)
	#@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ_SRC) $(OBJ_LIB)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@make -C $(LIB_PATH) clean
	@$(RM) $(OBJ_SRC)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
