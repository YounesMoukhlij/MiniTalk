/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:45 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/22 02:08:06 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	show_mssg(int check)
{
	static int i;

	if (check == SIGUSR1)
		printf("%d sent", i++);
	else if (check == SIGUSR2)
		i++;
}

static void	transmit_mssg(int pid, unsigned char c)
{
	int	i;

	i = 0x0;
	while (i < 8)
	{
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR2);
		else if ((c & (0x01 << i)) == 0)
			kill(pid, SIGUSR1);
		i++;
		pause ();
		usleep(100);
	}
}

int	main(int ac, char *av[])
{
	int pid;
	int	i;
	i = 0x0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		while (av[2][i] != '\0')
		{
			signal(SIGUSR2, show_mssg);
			signal(SIGUSR1, show_mssg);
			transmit_mssg(pid, av[2][i]);
			i++;
			usleep(10);
		}
		transmit_mssg(pid, '\0');
	}
	else
		printf("***( ERROR -_-! )***\nTRY =>> ./client <server_pid> <text to send>\n");
	return (0);
}
