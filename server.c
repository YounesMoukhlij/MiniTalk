/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:51 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/22 01:58:05 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static void	recieve_mssg(int signal_value, siginfo_t *t, void *a)
{
    static int	index;
    static unsigned char	octet;
	static int mssg_env;
	static int client;
	static int current;

	(void)a;
	(void)t;
	if (!client)
		client = t->si_pid;
	current = t->si_pid;
	if (client != current)
	{
		client = t->si_pid;
		octet = 0;
		index = 0;
		mssg_env = 0;
	}
	if (signal_value == SIGUSR2)
		octet = octet | (0x01 << index);
	if (signal_value == SIGUSR1)
		octet = octet | (0x00 << index);
	index++;
	mssg_env++;
	if (index == 8)
	{
		printf("%c", octet);
		if (octet == '\0')
		{
			printf("\n%d messages recieved\n", mssg_env);
			mssg_env = 0x0;
			kill(client, SIGUSR1);
		}
		octet = 0x0;
		index = 0x0;
	}
	usleep(100);
	kill(client, SIGUSR2);
}

int	main(void)
{
	int pid = getpid();

	struct sigaction sss;

	sss.sa_sigaction = recieve_mssg;
	sigemptyset(&sss.sa_mask);
	sss.sa_flags =  SA_SIGINFO;
    printf("My Server's PID : %d\n", pid);
	printf("\033[90mWaiting for a message...\033[0m\n");
    while (1)
	{
    	sigaction(SIGUSR1, &sss, NULL);
    	sigaction(SIGUSR2, &sss, NULL);
		pause();
	}
    return (0);
}
