/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:51 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/19 01:34:17 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static void	recieve_mssg(int signal_value)
{
    static int	index = 0;
    static int	octet = 0;
	static int mssg_env = 0;

	if (signal_value == SIGUSR1)
		octet = octet | (0x01 << index);
	index++;
	mssg_env++;
	if (index == 8)
	{
		printf("%c", octet);
		if ((char)octet == '\0')
			printf("%d messages recieved\n", mssg_env);
		index = 0x0;
		octet = 0x0;
	}
}

int	main(void)
{
	int pid = getpid();

    printf("My Server's PID : %d\n", pid);
	printf("\033[90mWaiting for a message...\033[0m\n");
    while (1)
	{
    	signal(SIGUSR1, recieve_mssg);
    	signal(SIGUSR2, recieve_mssg);
		pause();
	}
    return (0);
}
