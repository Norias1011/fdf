/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:34:24 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/19 16:29:42 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	h_manage(t_env *env)
{
	mlx_key_hook(env->win, key_handler, env);
	mlx_hook(env->win, 17, 0, close_win, env);
	// mlx_mouse_get_pos(env->mlx, env->win, env->mousex, env->mousey);
	mlx_mouse_hook(env->win, mouse_handler, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, key_handler, env);
}

int	key_handler(int key, t_env *env)
{
	if (key == 53)
		close_win(env);
	else if (key == XK_Escape)
		close_win(env);
	else if (key == XK_Up || key == XK_w || key == XK_W)
		env->translation -= 10;
	else if (key == XK_Down || key == XK_s || key == XK_S)
		env->translation += 10;
	else if (key == XK_Left || key == XK_a || key == XK_A)
		env->angle += 0.01;
	else if (key == XK_Right || key == XK_d || key == XK_D)
		env->angle -= 0.01;
	else if (key == XK_z || key == XK_Z)
		env->altitude += 0.1;
	else if (key == XK_h || key == XK_H)
		env->altitude -= 0.1;
	return (0);
}

int	close_win(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->image);
	mlx_destroy_display(env->mlx);
	free_tab1(env);
	exit(0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	x -= 1920 / 2;
	y -= 1080 / 2;
	if (mousecode == 4)
	{
		env->scale *= 1.1;
		env->mousex += x / env->scale / 2.51;
		env->mousey -= y / env->scale / 2.51;
	}
	else if (mousecode == 5)
	{
		env->scale /= 1.1;
	}
	return (0);
}
