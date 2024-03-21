/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:10:20 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/19 16:31:32 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	three_point(t_env *env)
{
	int	i;

	i = 0;
	env->init_dim = malloc(sizeof(t_init) * env->map_h * env->map_l);
	if (!env->init_dim)
		error_mes("Error Malloc");
	env->y = 0;
	while (env->y < env->map_h)
	{
		env->x = 0;
		while (env->x < env->map_l)
		{
			env->init_dim[i] = (t_init){env->x, env->y,
				env->final_map[env->y][env->x]};
			i++;
			env->x++;
		}
		env->y++;
	}
	free_tab(env);
}

void	two_point(t_env *env)
{
	int	i;

	i = 0;
	env->final_dim = malloc(sizeof(t_final) * env->map_h * env->map_l);
	if (!env->final_dim)
		error_mes("Error Malloc");
	while (i < (env->map_l * env->map_h))
	{
		env->final_dim[i].y = env->init_dim[i].y * cosf(env->angle)
			+ env->init_dim[i].y * cosf(env->angle + 2) + (env->init_dim[i].z
				* env->altitude) * cosf(env->angle - 2);
		env->final_dim[i].x = env->init_dim[i].x * sinf(env->angle)
			+ env->init_dim[i].y * sinf(env->angle + 2) + (env->init_dim[i].z
				* env->altitude) * sinf(env->angle - 2);
		env->final_dim[i].x *= -env->scale;
		env->final_dim[i].y *= env->scale;
		i++;
	}
}
