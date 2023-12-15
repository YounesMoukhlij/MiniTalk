/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:28:09 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/22 16:42:24 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *counter)
{
	int	i;

	i = 0;
	if (!s)
	{
		*counter += write(1, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], counter);
		i++;
	}
}
