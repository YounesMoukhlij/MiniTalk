SRC = server.c client.c

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = minitalk.h


all : ${HEADER}
	cc ${CFLAGS} server.c -o server
	cc ${CFLAGS} client.c -o client

clean :
	${RM} server client
