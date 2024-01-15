/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:45 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/07 13:14:42 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	alert_message(int check_sig)
{
	static int	i;

	if (check_sig == SIGUSR1)
		ft_printf(SUCC_M_C, ++i);
	else if (check_sig == SIGUSR2)
		i++;
}

void	send_message(int pid, unsigned char c)
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
		ft_printf(ERROR_M);
		return (0x1);
	}
	return (0x0);
}
