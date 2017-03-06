# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aazri <aazri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 17:35:54 by aazri             #+#    #+#              #
#    Updated: 2017/02/16 18:52:39 by aazri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft
LIB_PATH = ./libft/
LIB_BIN = $(LIB_PATH)libft.a
RM = rm -f

SRC =	ft_printf.c \
		handle_characters.c \
		handle_decimal.c \
		handle_hexadecimal.c \
		handle_octal.c \
		length_specifier.c \
		parsing_flags.c \
		utils.c \
		valid_format.c \
		get_func_array.c \

OBJ = $(SRC:.c=.o)
OBJ_LIB = $(LIB_PATH)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ) $(LIB_PATH)*.o
	@ranlib $(NAME)

all: $(NAME)

clean:
	@make -C $(LIB_PATH) clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
