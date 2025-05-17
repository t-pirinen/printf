/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:46:20 by tpirinen          #+#    #+#             */
/*   Updated: 2025/05/17 05:13:42 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_printhex(uintptr_t n, int fd);

/*	Prints the memory address of a pointer to file descriptor. Returns number
	of characters printed or -1 on error.									*/
ssize_t		ft_putptr_fd(void *ptr, int fd)
{
	ssize_t		err;

	if (!ptr)
		return (write(fd, "(nil)", 5));
	err = write(fd, "0x", 2);
	if (err == -1)
		return (err);
	err += ft_printhex((uintptr_t)ptr, fd);
	if (err == -1)
		return (err);
	return (err);
}

static ssize_t	ft_printhex(uintptr_t n, int fd)
{
	ssize_t		chars_printed;
	ssize_t		err;
	
	chars_printed = 0;
	if (n >= 16)
	{
		err = ft_printhex(n / 16, fd);
		if (err == -1)
			return (err);
		chars_printed += err;
	}
	err = write(fd, &HEX_LOWER[n % 16], 1);
	if (err == -1)
		return (err);
	chars_printed += err;
	return (chars_printed);
}
