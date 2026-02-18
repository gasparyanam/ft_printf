/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <agaspary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:54:23 by agaspary          #+#    #+#             */
/*   Updated: 2026/02/19 01:02:25 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_determinant(const char *format, va_list arg)
{
	int	count;

	count = 0;
	if (*format == '%')
		count += ft_putchar_bc('%');
	else if (*format == 'c')
		count += ft_putchar_bc(va_arg(arg, int));
	else if (*format == 's')
		count += ft_putstr_bc(va_arg(arg, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr_bc(va_arg(arg, int));
	else if (*format == 'u')
		count += ft_putunit_bc(va_arg(arg, unsigned int));
	else if (*format == 'x')
		count += ft_puthex_bc(va_arg(arg, unsigned int), 'x');
	else if (*format == 'X')
		count += ft_puthex_bc(va_arg(arg, unsigned int), 'X');
	else if (*format == 'p')
		count += ft_putptr_bc(va_arg(arg, unsigned long));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		bytes;

	bytes = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			bytes += ft_determinant(format++, arg);
			continue ;
		}
		else
			ft_putchar_fd(*format, 1);
		bytes++;
		format++;
	}
	va_end(arg);
	return (bytes);
}
