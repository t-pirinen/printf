/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:45:33 by tpirinen          #+#    #+#             */
/*   Updated: 2025/05/16 20:14:26 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_parse_args(const char *s, int i, va_list args);

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
			chars_printed = ft_parse_args(s, &i, args);
			i += 2;
		}
		else
			i++;
	}
	va_end(args);
	return (chars_printed);
}

static ssize_t	ft_parse_args(const char *s, int i, va_list args)
{
	int			fd;
	ssize_t		chars_printed;
	
	chars_printed = 0;
	fd = 0;
	if (s[i + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), fd);
	else if (s[i + 1] == 's')
		ft_putstr_fd(va_arg(args, char *), fd);
	// else if (s[i + 1] == 'p')
		
	// else if (s[i + 1] == 'd')
		
	// else if (s[i + 1] == 'i')
		
	// else if (s[i + 1] == 'u')
		
	// else if (s[i + 1] == 'x')
		
	// else if (s[i + 1] == 'X')
		
	// else if (s[i + 1] == '%')
		
	return (chars_printed);
}
