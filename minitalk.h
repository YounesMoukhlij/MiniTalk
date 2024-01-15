/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:56:26 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/28 15:04:48 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf/ft_printf.h"

# define ERROR_M "\033[31mTRY =>> ./client <server_pid> <text to send>\033[0m\n"
# define SUCC_M_S "\n\033[32m%d Signal Recieved Successfully\033[0m\n"
# define SUCC_M_C "\033[33m%d Signal Sent Successfully (* _ *)\033[32m\n"
# define WAIT_M "\033[90mWaiting for a message...\033[0m\n"

#endif