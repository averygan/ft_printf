/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:43:58 by agan              #+#    #+#             */
/*   Updated: 2023/09/12 14:43:59 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parseformat(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == '%')
		count += ft_putchar('%');
	else if (format == 'u')
		ft_putunsign(va_arg(args, size_t));
	else if (format == 'x' || format == 'X')
		count += ft_puthex(va_arg(args, size_t), format);
	else if (format == 'p')
	{
		/* add logic for null pointer */
		write (1, "0x", 2);
		count += 2;
		count += ft_puthex(va_arg(args, size_t), 'x');
	}
	else
		count += ft_putchar(format);
	return (count);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_parseformat(str[++i], args);
		else
			count += ft_putchar(*(str + i));
		i++;
	}
	return (count);
}

int	main(void)
{
	int	digits;
	digits = 0;
	char *s;
	s = NULL;
	/*My printf*/
	printf("My printf:\n");
	digits = ft_printf("This is a string %p\n", s);
	printf("Chars printed: %d\n\n", digits);
	/*Original printf*/
	printf("Original printf:\n");
	digits = printf("This is a string %p\n", s);
	printf("Chars printed: %d\n", digits);
}