/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:51 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/07 13:14:29 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_pid_handler(siginfo_t *sig_infos, int *client_pid, int *actual_pid)
{
	if (!(*client_pid))
		*client_pid = sig_infos->si_pid;
	*actual_pid = sig_infos->si_pid;
}

void	ft_bit_handler(int sig_v, int *index, unsigned char *carac)
{
	if (sig_v == SIGUSR2)
		*carac |= (0x1 << *index);
	else if (sig_v == SIGUSR1)
		*carac |= (0x0 << *index);
}

void	char_handler(int c_pid, unsigned char *o, int *s_mssg, int *i)
{
	if (*o == '\0')
	{
		ft_printf(SUCC_M_S, *s_mssg);
		*s_mssg = 0x0;
		(void) c_pid;
		kill(c_pid, SIGUSR1);
	}
	*o = 0x0;
	*i = 0x0;
}

void	recieve_mssg(int signal_value, siginfo_t *sig_infos, void *nothing)
{
	static int				signal_message;
	static int				client_pid;
	static int				actual_pid;
	static int				index;
	static unsigned char	received_carac;

	(void)nothing;
	ft_pid_handler(sig_infos, &client_pid, &actual_pid);
	if (client_pid != actual_pid)
	{
		client_pid = sig_infos->si_pid;
		received_carac = 0x0;
		index = 0x0;
		signal_message = 0x0;
	}
	ft_bit_handler(signal_value, &index, &received_carac);
	index++;
	signal_message++;
	if (index == 0x8)
	{
		write (1, &received_carac, 1);
		char_handler(client_pid, &received_carac, &signal_message, &index);
	}
	usleep(100);
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	int					pid;
	struct sigaction	signals_handler;

	pid = getpid();
	sigemptyset(&signals_handler.sa_mask);
	signals_handler.sa_flags = 0x0040;
	signals_handler.sa_sigaction = recieve_mssg;
	ft_printf("My Server's PID : %d\n", pid);
	ft_printf(WAIT_M);
	while (1337)
	{
		sigaction(SIGUSR1, &signals_handler, NULL);
		sigaction(SIGUSR2, &signals_handler, NULL);
		pause();
	}
	return (0);
}
