/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fplus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <agaspary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:54:39 by agaspary          #+#    #+#             */
/*   Updated: 2026/02/18 21:26:00 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_bc(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr_bc(char *str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	return (count);
}

int	ft_putnbr_bc(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 1;
	ft_putnbr_fd(n, 1);
	if (nb < 0)
	{
		count = 2;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_putunit_bc(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunit_bc(n / 10);
	}
	count += ft_putchar_bc(n % 10 + '0');
	return (count);
}
