/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:54:51 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/18 20:08:30 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static void	recieve_mssg(int signal_value)
{
    static int				index = 0;
    static unsigned char	octet = 0;
	
	octet <<= 1;
	// while (index < 8)
	// {
		if (signal_value == SIGUSR1)
			octet |= (1 << index);
		// else if (signal_value == SIGUSR2)
		// 	octet |= (0 << index);
		index++;
	
	printf("%c", octet);
	index = 0;

}

int	main(void)
{
	int pid = getpid();
	
    printf("My Server's PID : %d\n", pid);
    signal(SIGUSR1, recieve_mssg);
    signal(SIGUSR2, recieve_mssg);
    while (1)
	{
		pause();
	}
    return (0);
}

/*
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void receive_msg(int signal_value) {
    static int index = 0;
    static unsigned char octet = 0;

    // Shift the existing bits to make space for the new bit
    octet <<= 1;

    if (signal_value == SIGUSR1) {
        // Set the least significant bit to 1
        octet |= 1;
    } else if (signal_value == SIGUSR2) {
        // Set the least significant bit to 0 (no need to do anything, it's already 0)
    }

    index++;

    if (index == 8) {
        // Process the complete octet
        printf("%c", octet);
        octet = 0;
        index = 0;
    }
}

int main(void) {
    int pid = getpid();

    printf("My Server's PID: %d\n", pid);

    signal(SIGUSR1, receive_msg);
    signal(SIGUSR2, receive_msg);

    while (1) {
        pause();
    }

    return 0;
}
*/
