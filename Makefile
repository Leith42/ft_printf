# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aazri <aazri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 17:35:54 by aazri             #+#    #+#              #
#    Updated: 2017/01/27 18:14:35 by aazri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft
LIB_PATH = ./libft/
RM = rm -f

SRC = $(LIB_PATH)ft_memset.c $(LIB_PATH)ft_bzero.c $(LIB_PATH)ft_memcpy.c $(LIB_PATH)ft_memccpy.c \
$(LIB_PATH)ft_memmove.c $(LIB_PATH)ft_memchr.c $(LIB_PATH)ft_memcmp.c $(LIB_PATH)ft_memalloc.c $(LIB_PATH)ft_memdel.c \
$(LIB_PATH)ft_strlen.c $(LIB_PATH)ft_strdup.c $(LIB_PATH)ft_strcpy.c $(LIB_PATH)ft_strncpy.c $(LIB_PATH)ft_strcat.c $(LIB_PATH)ft_strncat.c \
$(LIB_PATH)ft_strlcat.c $(LIB_PATH)ft_strchr.c $(LIB_PATH)ft_strrchr.c $(LIB_PATH)ft_strstr.c $(LIB_PATH)ft_strnstr.c \
$(LIB_PATH)ft_strcmp.c $(LIB_PATH)ft_strncmp.c $(LIB_PATH)ft_atoi.c \
$(LIB_PATH)ft_isalpha.c $(LIB_PATH)ft_isdigit.c $(LIB_PATH)ft_isalnum.c $(LIB_PATH)ft_isascii.c $(LIB_PATH)ft_isprint.c \
$(LIB_PATH)ft_toupper.c $(LIB_PATH)ft_tolower.c \
$(LIB_PATH)ft_strnew.c $(LIB_PATH)ft_strdel.c $(LIB_PATH)ft_strclr.c $(LIB_PATH)ft_striter.c $(LIB_PATH)ft_striteri.c \
$(LIB_PATH)ft_strmap.c $(LIB_PATH)ft_strmapi.c $(LIB_PATH)ft_strequ.c $(LIB_PATH)ft_strnequ.c $(LIB_PATH)ft_strsub.c $(LIB_PATH)ft_strjoin.c \
$(LIB_PATH)ft_strtrim.c $(LIB_PATH)ft_strsplit.c \
$(LIB_PATH)ft_putchar.c $(LIB_PATH)ft_putstr.c $(LIB_PATH)ft_putendl.c $(LIB_PATH)ft_putnbr.c $(LIB_PATH)ft_putchar_fd.c \
$(LIB_PATH)ft_putstr_fd.c $(LIB_PATH)ft_putendl_fd.c $(LIB_PATH)ft_putnbr_fd.c $(LIB_PATH)ft_itoa.c \
$(LIB_PATH)ft_lstnew.c	$(LIB_PATH)ft_lstdelone.c $(LIB_PATH)ft_lstdel.c $(LIB_PATH)ft_lstadd.c $(LIB_PATH)ft_lstiter.c $(LIB_PATH)ft_lstmap.c \
$(LIB_PATH)ft_strndup.c $(LIB_PATH)ft_sqroot.c $(LIB_PATH)ft_strtoupper.c $(LIB_PATH)ft_strtolower.c ft_printf.c \
$(LIB_PATH)ft_strtolower.c $(LIB_PATH)ft_strtoupper.c $(LIB_PATH)ft_strrev.c $(LIB_PATH)ft_putlnbr.c $(LIB_PATH)ft_putulnbr.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
