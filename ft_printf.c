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
		count += ft_putunsigned(va_arg(args, unsigned int));
	/*if (format == 'p')
	if (format == 'x')
	if (format == 'X')*/
	return (count);
}

int ft_printf(const char *str, ...)
{
	// Variadic arguments
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
	char s[] = "bye!";
	/*My printf*/
	printf("My printf:\n");
	digits = ft_printf("This is a string %u\n", -100);
	printf("Chars printed: %d\n\n", digits);
	/*Original printf*/
	printf("Original printf:\n");
	digits = printf("This is a string %u\n", -100);
	printf("Chars printed: %d\n", digits);
}