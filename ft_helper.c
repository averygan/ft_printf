/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:48:54 by agan              #+#    #+#             */
/*   Updated: 2023/09/12 17:49:08 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Helper functions for output*/
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		count += 6;
		return (count);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

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
	char *hex;
	int	base;
	int	count;

	hex = "0123456789abcdef";
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