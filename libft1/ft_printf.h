/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:52:25 by akinzeli          #+#    #+#             */
/*   Updated: 2024/02/28 12:52:08 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

void	ft_putnbr_base(unsigned long long nb, unsigned long long s, char *base);
int		checkp(unsigned long long p);
int		checkx(char c, unsigned int num);
int		checkc(int c);
int		checks(char *str);
int		checkdi(int n);
int		checku(unsigned int n);
int		checkchar(char c, va_list args);
int		ft_printf(const char *format, ...);

#endif 
