/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_low_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:51:14 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/15 15:02:25 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_low_hex(unsigned long long n, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (16 <= n)
	{
		ft_print_low_hex(n / 16, counter);
		ft_print_low_hex(n % 16, counter);
	}
	else
		ft_putchar(base[n], counter);
}
