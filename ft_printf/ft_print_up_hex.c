/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_up_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:38 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/15 15:02:30 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_up_hex(unsigned long long n, int *counter)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (16 <= n)
	{
		ft_print_up_hex(n / 16, counter);
		ft_print_up_hex(n % 16, counter);
	}
	else
		ft_putchar(base[n], counter);
}
