# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 13:23:56 by youmoukh          #+#    #+#              #
#    Updated: 2024/01/07 13:09:40 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

server_c = server.c
client_c = client.c

server_o = server.o
client_o = client.o

Server = server
Client = client

libftprintf = ft_printf/libftprintf.a
libftprintf_directory = ft_printf

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER_MINITALK = minitalk.h
HEADER_FT_PRINTF = ft_printf/ft_printf.h

all : ${Server} ${Client} ${libftprintf}
	
${Server} : ${HEADER_MINITALK} ${server_o} ${libftprintf}
	cc ${CFLAGS} ${libftprintf} ${server_c} -o $@

${Client} : ${HEADER_MINITALK} ${client_o} ${libftprintf}
	cc ${CFLAGS} ${libftprintf} ${client_c} -o $@ 

${libftprintf} : ${HEADER_FT_PRINTF}
	@${MAKE} -C ${libftprintf_directory}

%.o : %.c ${HEADER_MINITALK}
	cc ${CFLAGS} -c $< -o $@ 

clean :
	@${RM} ${server_o} ${client_o}
	@${MAKE} clean -C ${libftprintf_directory}

fclean : clean
	@${RM} ${Server} ${Client}
	@${MAKE} fclean -C ${libftprintf_directory}

re : fclean all

.PHONY : all clean fclean re