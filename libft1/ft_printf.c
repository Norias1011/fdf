/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:32:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/02/28 12:48:59 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkchar(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += checkc(va_arg(args, int));
	else if (c == 's')
		count += checks(va_arg(args, char *));
	else if (c == 'p')
		count += checkp(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		count += checkdi(va_arg(args, int));
	else if (c == 'u')
		count += checku(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += checkx(c, va_arg(args, unsigned int));
	else if (c == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count = count + checkchar(format[i + 1], args);
			i++;
		}
		else
		{
			count++;
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
