/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <agaspary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 02:03:06 by agaspary          #+#    #+#             */
/*   Updated: 2026/02/18 21:30:03 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_bc(unsigned long dec, int x)
{
	int		count;
	char	*base;

	base = "";
	if (x == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (dec >= 16)
	{
		count += ft_puthex_bc(dec / 16, x);
		count += ft_putchar_bc(base[dec % 16]);
	}
	else
		count += ft_putchar_bc(base[dec]);
	return (count);
}

int	ft_putptr_bc(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (ft_putstr_bc("(nil)"));
	count += ft_putstr_bc("0x");
	count += ft_puthex_bc(n, 'x');
	return (count);
}
