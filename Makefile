# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 21:57:41 by jgan              #+#    #+#              #
#    Updated: 2015/12/17 19:05:59 by lnagy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = fillit

SRC = fillit.c \
	lst.c \
	do_lst.c \
	ft_bzero.c \
	ft_gnl.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putendl.c \
	ft_putstr.c \
	ft_putstrtab.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strndup.c \
	ft_strnew.c \
	ft_memalloc.c \
	ft_strncpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -o $(NAME) $(SRC)
	@echo "fillit created"

clean:
	@rm -f $(OBJ)
	@echo "fillit *.o deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "fillit deleted"

re: fclean all

.PHONY: all, clean, fclean, re
