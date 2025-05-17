/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:21:25 by tpirinen          #+#    #+#             */
/*   Updated: 2025/05/17 05:12:43 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Prints an unsigned int to file descriptor and returns number of
	chars printed. Returns -1 on error.										*/
int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	err;
	int	chars_printed;

	chars_printed = 0;
	if (n > 9)
	{
		err = ft_putunbr_fd(n / 10, fd);
		if (err == -1)
			return (err);
		chars_printed += err;
		err = ft_putunbr_fd(n % 10, fd);
		if (err == -1)
			return (err);
		chars_printed += err;
	}
	else
	{
		n += '0';
		err = write(fd, &n, 1);
		if (err == -1)
			return (err);
		chars_printed += err;
	}
	return (chars_printed);
}
