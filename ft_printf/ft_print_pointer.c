/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:31:39 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/15 15:03:43 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(void *p, int *counter)
{
	ft_putstr("0x", counter);
	ft_print_low_hex((unsigned long long)p, counter);
}
