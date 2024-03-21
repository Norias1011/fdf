/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initwin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:45:20 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/19 15:30:36 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	window_init(t_env *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		free(env->mlx);
		return (1);
	}
	env->win = mlx_new_window(env->mlx, 1920, 1080, "Fdf");
	if (env->win == NULL)
		return (1);
	env->image = mlx_new_image(env->mlx, 1920, 1080);
	env->address = mlx_get_data_addr(env->image, &env->bits_by_pixel,
			&env->line_length, &env->endian);
	two_point(env);
	limits(env);
	h_manage(env);
	mlx_loop_hook(env->mlx, render, env);
	mlx_loop(env->mlx);
	return (0);
}

int	render(t_env *env)
{
	draw_background(env);
	two_point(env);
	limits(env);
	mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
	return (0);
}
