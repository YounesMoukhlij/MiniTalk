/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:51:04 by youmoukh          #+#    #+#             */
/*   Updated: 2023/12/22 23:34:16 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *counter);
void	ft_print_low_hex(unsigned long long n, int *counter);
void	ft_print_up_hex(unsigned long long n, int *counter);
void	ft_putnbr(long n, int *counter);
void	ft_putstr(char *s, int *counter);
int		ft_atoi(char *str);
int		ft_strlen(char *s);
void	ft_print_pointer(void *p, int *counter);

#endif
