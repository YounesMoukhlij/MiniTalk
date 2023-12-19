/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:45 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/19 01:36:17 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static void	show_mssg(int check)
{
	if (check == SIGUSR1 || check == SIGUSR2)
		printf("Message sent\n");
	else
		printf("NOT SENT\n");
}

static void	transmit_mssg(int pid, char c)
{
	int	i;

	i = 0x0;
	while (i < 8)
	{
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int ac, char *av[])
{
	int pid;
	int	i;

	pid = atoi(av[1]);
	i = 0x0;
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			signal(SIGUSR1, show_mssg);
			signal(SIGUSR2, show_mssg);
			transmit_mssg(pid, av[2][i]);
			i++;
		}
		transmit_mssg(pid, '\n');
	}
	else
		printf("***( ERROR -_-! )***\nTRY =>> ./client <server_pid> <text to send>\n");
	return (0);
}
