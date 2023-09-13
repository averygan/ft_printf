/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:45:46 by agan              #+#    #+#             */
/*   Updated: 2023/09/12 14:45:49 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

/*help functions*/
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_toupper(int c);

/*parse numbers*/
int	ft_putnbr(int n);
int	ft_putunsign(unsigned int n);
int	ft_puthex(size_t n, char c);

#endif
