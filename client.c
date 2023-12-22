/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:45 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/22 23:38:08 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	alert_message(int check_sig)
{
	static int	i;

	if (check_sig == SIGUSR1)
		ft_printf("\033[32m%d Signal Sent Successfully (* _ *)\033[0m\n", ++i);
	else if (check_sig == SIGUSR2)
		i++;
}

static void	send_message(pid_t pid, unsigned char c)
{
	int	i;

	i = 0x0;
	while (i < 0x8)
	{
		if ((c & (0x01 << i)) != 0x0)
			kill(pid, SIGUSR2);
		else if ((c & (0x01 << i)) == 0x0)
			kill(pid, SIGUSR1);
		i++;
		pause();
		usleep(100);
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	if (ac == 0x3)
	{
		i = 0x0;
		pid = ft_atoi(av[0x1]);
		while (av[0x2][i] != '\0')
		{
			signal(SIGUSR2, alert_message);
			signal(SIGUSR1, alert_message);
			send_message(pid, av[0x2][i]);
			i++;
		}
		send_message(pid, '\0');
	}
	else
	{
		ft_printf("ERROR -_-!\nTRY =>> ./client <server_pid> <text to send>\n");
		return (0x1);
	}
	return (0x0);
}
