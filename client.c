/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:45 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/15 16:32:33 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// #include "ft_printf/ft_printf.h"

static void	signal_mssg(int check)
{
	static int recieved_signals;
	
	if (check == SIGUSR1)
	{
		printf("%d Signal Sent Successfully\n", recieved_signals++);
		exit (EXIT_SUCCESS);
	}
	else if (check == SIGUSR2)
		recieved_signals++; 
}

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
		i = 8;
		while (i)
		{
			if (octet >> i & 1)
				if (!kill(pid, SIGUSR2))
					sending_error();
			else
				if (!kill(pid, SIGUSR1))
					sending_error();
			i--;
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
	}
}

int	main(int ac, char *av[])
{
	int	the_server_pid;

	if (!ft_strlen(av[2]));
		return (1);
	the_server_pid = atoi(av[1]);
	if (ac == 3)
	{
		signal(SIGUSR1, signal_mssg);
		signal(SIGUSR2, signal_mssg);
		transmit_mssg(ft_atoi(av[1]), av[2]);
	}
	else
		printf("***( ERROR -_-! )***\nTRY =>> ./client <server_pid> <text to send>\n");
	return (0);
}
