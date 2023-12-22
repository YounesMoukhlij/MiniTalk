# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 23:06:00 by younesmoukh       #+#    #+#              #
#    Updated: 2023/12/22 23:37:26 by younesmoukh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Server = server
Client = client

server_c = server.c
client_c = client.c

server_obj = server.o
client_obj = client.o

libftprintf_directory = ft_printf
libftprintf = ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

HEADER = minitalk.h
HEADER_PRINTF = ft_printf/ft_printf.h


all : ${libftprintf} ${Server} ${Client}


${Server} : ${HEADER} ${server_obj}
	cc ${CFLAGS} ${libftprintf} ${server_c} -o $@

${Client} : ${HEADER} ${client_obj}
	cc ${CFLAGS} ${libftprintf} ${client_c} -o $@

${libftprintf} : ${HEADER_PRINTF}
	${MAKE} -C ${libftprintf_directory}

%.o : %.c ${HEADER}
	cc ${CFLAGS} -c $< -o $@

clean :
	${RM} ${server_obj} ${client_obj}
	${MAKE} clean -C ${libftprintf_directory}

fclean : clean
	${RM} server client
	${MAKE} fclean -C ${libftprintf_directory}

re : fclean all

.PHONY : re all clean fclean
