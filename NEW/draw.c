/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:44:21 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/14 18:07:37 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_env *env, t_final point1, t_final point2)
{
	int	error;
	int	x;
	int	y;
	int	i;

	env->pixel_coor->dx = abs(point2.x - point1.x);
	env->pixel_coor->dy = abs(point2.y - point1.y);
	env->incrx = (point1.x < point2.x) ? 1 : -1;
	env->incry = (point1.y < point2.y) ? 1 : -1;
	error = (env->pixel_coor->dx > env->pixel_coor->dy) ? (env->pixel_coor->dx
			/ 2) : (-env->pixel_coor->dy / 2);
	x = point1.x;
	y = point1.y;
	i = 0;
	while (i++ <= ((env->pixel_coor->dx > env->pixel_coor->dy) ? env->pixel_coor->dx : env->pixel_coor->dy))
	{
		put_line(env, x, y, 0xFFFFFF);
		if (env->pixel_coor->dx > env->pixel_coor->dy)
		{
			error -= env->pixel_coor->dy;
			if (error < 0)
			{
				y += env->incry;
				error += env->pixel_coor->dx;
			}
			x += env->incrx;
		}
		else
		{
			error -= env->pixel_coor->dx;
			if (error < 0)
			{
				x += env->incrx;
				error += env->pixel_coor->dy;
			}
			y += env->incry;
		}
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
	int h;
	int l;

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