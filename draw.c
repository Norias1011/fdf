/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:44:21 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/19 16:25:20 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_env *env, t_final point1, t_final point2)
{
	float		step;
	float		x;
	float		y;
	int			i;
	t_pixcor	delta;

	i = 0;
	delta.dx = point2.x - point1.x;
	delta.dy = point2.y - point1.y;
	if (fabsf(delta.dx) >= fabsf(delta.dy))
		step = fabsf(delta.dx);
	else
		step = fabsf(delta.dy);
	delta.dx = delta.dx / step;
	delta.dy = delta.dy / step;
	x = point1.x;
	y = point1.y;
	while (i < step)
	{
		put_line(env, -x + 1920 / 2 + env->translation + env->mousex, -y + 1080
			/ 2 + env->translation - env->mousey, 0xFFFFFF);
		x = x + delta.dx;
		y = y + delta.dy;
		i++;
	}
}

void	put_line(t_env *env, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		pxl = env->address + (y * env->line_length + x * (env->bits_by_pixel
					/ 8));
		*(unsigned int *)pxl = color;
	}
}

void	draw_background(t_env *env)
{
	int	h;
	int	l;

	h = 0;
	l = 0;
	while (h <= 1080)
	{
		l = 0;
		while (l <= 1920)
		{
			put_line(env, l, h, 0x000000);
			l++;
		}
		h++;
	}
}
