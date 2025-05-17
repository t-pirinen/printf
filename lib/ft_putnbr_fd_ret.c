/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_ret.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:09:33 by tpirinen          #+#    #+#             */
/*   Updated: 2025/05/17 05:13:58 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_putnbr_ll_fd_ret(long long n, int fd);

/*	Writes the given integer 'n' to the given file descriptor 'fd' and
	returns the number of chars printed. Returns -1 on error.				*/
ssize_t	ft_putnbr_fd_ret(int nbr, int fd)
{
    return ft_putnbr_ll_fd_ret((long long)nbr, fd);
}

static ssize_t	ft_putnbr_ll_fd_ret(long long n, int fd)
{
    ssize_t	err;
    ssize_t	chars_printed = 0;

    if (n < 0)
    {
        if (write(fd, "-", 1) == -1)
            return (-1);
        chars_printed++;
        n = -n;
    }
    if (n > 9)
    {
        err = ft_putnbr_ll_fd_ret(n / 10, fd);
        if (err == -1)
            return (err);
        chars_printed += err;
    }
    err = ft_putchar_fd_ret((n % 10) + '0', fd);
    if (err == -1)
        return (err);
    chars_printed += err;
    return (chars_printed);
}
