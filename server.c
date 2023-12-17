/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:51 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/17 18:16:37 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// #include "ft_printf/ft_printf.h"

static void	recieve_mssg(int check)
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

int	main(void)
{
	int					pid;
	
	pid = getpid();
	printf("My Server's PID : %d \n", pid);
	signal(SIGUSR1, recieve_mssg);
	signal(SIGUSR2, recieve_mssg);
	while (1)
	{
		pause ();
	}
}
