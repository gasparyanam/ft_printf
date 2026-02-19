/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspary <agaspary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:54:50 by agaspary          #+#    #+#             */
/*   Updated: 2026/02/19 15:17:00 by agaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_bc(int c);
int	ft_putstr_bc(char *str);
int	ft_putnbr_bc(int n);
int	ft_putunit_bc(unsigned int n);
int	ft_puthex_bc(unsigned long long n, int upper);
int	ft_putptr_bc(unsigned long long n);

#endif
