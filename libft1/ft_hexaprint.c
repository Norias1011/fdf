/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:53:46 by akinzeli          #+#    #+#             */
/*   Updated: 2024/02/28 12:50:44 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nb, unsigned long long s, char *base)
{
	unsigned long long	d;

	d = nb;
	if (d >= s)
	{
		ft_putnbr_base(d / s, s, base);
		d = d % s;
	}
	if (d < s)
	{
		write(1, &base[d], 1);
	}
}

int	checkp(unsigned long long p)
{
	int	count;

	count = 0;
	if (p == 0)
	{
		count += write(1, "(nil)", 5);
	}
	else
	{
		count += write(1, "0x", 2);
		ft_putnbr_base(p, 16, "0123456789abcdef");
	}
	while (p != 0)
	{
		p = p / 16;
		count++;
	}
	return (count);
}

int	checkx(char c, unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (write(1, "0", 1));
	if (c == 'x')
		ft_putnbr_base(num, 16, "0123456789abcdef");
	else
		ft_putnbr_base(num, 16, "0123456789ABCDEF");
	while (num != 0)
	{
		num = num / 16;
		count++;
	}
	return (count);
}
