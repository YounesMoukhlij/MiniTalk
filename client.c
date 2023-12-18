/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:45 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/18 20:05:11 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static void	sending_error(void)
{
	printf("Error Sending The Msg\n");
	exit (EXIT_FAILURE);
}

static void	transmit_mssg(int pid, char *s)
{
	int		i;
	int		index;
	char	octet;
	
	index = 0;
	while (s[index])
	{
		octet = s[index++];
		i = 7;
		while (i)
		{
			if (octet >> i & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					sending_error();
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					sending_error();
			}
			sleep(1);
			i--;
		}
	}
	i = 8;
	while (i--)
		kill(pid, SIGUSR1);
	sleep(1);
}

int	main(int ac, char *av[])
{
	int	the_server_pid;

	if (!strlen(av[2]))
		return (1);
	the_server_pid = atoi(av[1]);
	if (ac == 3)
	{
		transmit_mssg(atoi(av[1]), av[2]);
	}
	else
		printf("***( ERROR -_-! )***\nTRY =>> ./client <server_pid> <text to send>\n");
	return (0);
}