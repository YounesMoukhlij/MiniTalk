/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:55 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/19 15:52:45 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long n, int *counter)
{
	if (n < 0)
	{
		ft_putchar('-', counter);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
	else
		ft_putchar(n + 48, counter);
}
