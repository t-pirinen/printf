/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:45:33 by tpirinen          #+#    #+#             */
/*   Updated: 2025/05/17 02:42:15 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_parse_args(char specifier, va_list args);

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	ssize_t		chars_printed;

	i = 0;
	chars_printed = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			chars_printed += ft_parse_args(s[i + 1], args);
			i += 2;
		}
		else
		{
			chars_printed += ft_putchar_fd_ret(s[i], 1);
			i += 1;
		}
	}
	va_end(args);
	return (chars_printed);
}

static ssize_t	ft_parse_args(char specifier, va_list args)
{
	int			fd;
	ssize_t		chars_printed;
	
	chars_printed = 0;
	fd = 1;
	if (specifier == 'c')
		chars_printed += ft_putchar_fd_ret(va_arg(args, int), fd);
	else if (specifier == 's')
		chars_printed += ft_putstr_fd_ret(va_arg(args, char *), fd);
	else if (specifier == 'p')
		chars_printed += ft_putptr_fd(va_arg(args, void *), fd);
	else if (specifier == 'd' || specifier == 'i')
		chars_printed += ft_putnbr_fd_ret(va_arg(args, int), fd);
	else if (specifier == 'u')
		chars_printed += ft_putunbr_fd(va_arg(args, unsigned int), fd);
	else if (specifier == 'x')
		chars_printed += ft_puthex_low_fd(va_arg(args, unsigned int), fd);
	else if (specifier == 'X')
		chars_printed += ft_puthex_up_fd(va_arg(args, unsigned int), fd);
	else if (specifier == '%')
		chars_printed += ft_putchar_fd_ret('%', fd);
	return (chars_printed);
}
