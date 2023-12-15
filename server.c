/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:51 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/15 16:35:56 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// #include "ft_printf/ft_printf.h"

void	my_server_banner(int pid)
{
	printf("/*************** MINITALK ***************\
		\n\t\t\t My Server's PID : %d \t\t\t\
		\n/*************** YOUMOUKH Server ***************\\n", pid);
}

int	main(void)
{
	int					pid;
	//struct sigaction	s_sigaction;
	
	pid = getpid();
	my_server_banner(pid);
}
