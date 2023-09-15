/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:45:06 by agan              #+#    #+#             */
/*   Updated: 2023/09/13 15:45:08 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Functions to parse numbers*/
int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		return (count + ft_putnbr(-n));
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		return (count + ft_putnbr(n % 10));
	}
	else
		return (count + ft_putchar(n + '0'));
}

int	ft_putunsign(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsign(n / 10);
		return (count + ft_putunsign(n % 10));
	}
	else
		return (count + ft_putchar (n + '0'));
}

int	ft_puthex(size_t n, char c)
{
	char *hex = "0123456789abcdef";
	size_t	base;
	int		count;

	count = 0;
	base = 16;
	if (n > base)
	{
		count += ft_puthex(n / base, c);
		return (count + ft_puthex(n % base, c));
	}
	else
	{
		if (c == 'x')
			return (count + ft_putchar(hex[n]));
		else
			return (count + ft_putchar(ft_toupper(hex[n])));
	}
	return (count);
}

int	ft_putpointer(size_t n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write (1, "(null)", 6);
		return (6);
	}
	count += 2;
	write (1, "0x", 2);
	count += ft_puthex(n, 'x');
	return (count);
}
