/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:50:07 by akinzeli          #+#    #+#             */
/*   Updated: 2024/02/28 11:56:35 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_un(unsigned int n, int fd)
{
	long	c;

	if (fd == 0)
		return ;
	c = n;
	if (c < 0)
	{
		write(fd, "-", 1);
		c = c * -1;
	}
	if (c >= 10)
	{
		ft_putnbr_fd(c / 10, fd);
		c = c % 10;
	}
	if (c < 10)
	{
		c = c + '0';
		write(fd, &c, 1);
	}
}

int	checkc(int c)
{
	int	count;

	count = 1;
	ft_putchar_fd(c, 1);
	return (count);
}

int	checks(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (count);
}

int	checkdi(int n)
{
	int	count;

	count = 0;
	ft_putnbr_fd(n, 1);
	if (n < 0)
		count = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	checku(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	else
		ft_putnbr_fd_un(n, 1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
