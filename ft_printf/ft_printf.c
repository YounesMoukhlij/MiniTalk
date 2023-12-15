/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:09:30 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/22 16:49:56 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhelp(va_list list, const char *str, int *counter, int *i)
{
	if (str[*i] == '%')
		ft_putchar(str[*i], counter);
	else if (str[*i] == 'd' || str[*i] == 'i')
		ft_putnbr(va_arg(list, int), counter);
	else if (str[*i] == 'c')
		ft_putchar(va_arg(list, int), counter);
	else if (str[*i] == 'x')
		ft_print_low_hex(va_arg(list, unsigned int), counter);
	else if (str[*i] == 'X')
		ft_print_up_hex(va_arg(list, unsigned int), counter);
	else if (str[*i] == 'p')
		ft_print_pointer(va_arg(list, void *), counter);
	else if (str[*i] == 's')
		ft_putstr(va_arg(list, char *), counter);
	else if (str[*i] == 'u')
		ft_putnbr(va_arg(list, unsigned int), counter);
	else
		ft_putchar(str[*i], counter);
	*i += 1;
}

int	ft_printf(const char *str, ...)
{
	va_list	func;
	int		i;
	int		counter;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(func, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i++], &counter);
		else if (str[i] == '%' && str[i + 1] == '\0')
			i++;
		else
		{
			i++;
			ft_printhelp(func, str, &counter, &i);
		}
	}
	va_end(func);
	return (counter);
}
