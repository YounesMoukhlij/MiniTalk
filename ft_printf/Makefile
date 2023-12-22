# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 12:44:09 by youmoukh          #+#    #+#              #
#    Updated: 2023/12/22 23:31:08 by younesmoukh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_putchar.c ft_print_low_hex.c ft_print_up_hex.c ft_putstr.c \
	  ft_print_pointer.c ft_putnbr.c ft_atoi.c ft_strlen.c \

OBJ = ${SRC:%.c=%.o}
CFLAGS = -Wall -Wextra -Werror
INC = ft_printf.h
NAME = libftprintf.a


all : ${NAME}

${NAME} : ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o : %.c ${INC}
	cc ${CFLAGS} -c $< -o $@

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all re fclean clean
