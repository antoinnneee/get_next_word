#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 13:03:04 by abureau           #+#    #+#              #
#    Updated: 2016/12/15 13:03:04 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = gnw

SRC = ./src/main.c

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra

all: LIBCOMPILE $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -I libft/includes -L libft/ -lft

LIBCOMPILE:
	 make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -I libft/includes -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
