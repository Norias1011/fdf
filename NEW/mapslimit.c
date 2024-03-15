/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapslimit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:12 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/14 17:52:57 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	limits(t_env *env)
{
	env->s_y = 1;
	env->i = 0;
	while (env->s_y != env->map_h)
	{
		env->s_x = 1;
		while (env->s_x < env->map_l)
			no_limit(env);
		if (env->s_x == env->map_l)
		{
			env->i++;
		}
		env->s_y++;
	}
	env->s_x = 1;
	if (env->s_y == env->map_h)
	{
		while (env->s_x != env->map_l)
		{
			env->i++;
		}
	}
	free(env->final_dim);
}

void	no_limit(t_env *env)
{
	right_limit(env);
	low_limit(env);
	env->i++;
}

void	right_limit(t_env *env)
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	x0 = env->final_dim[env->i].x;
	y0 = env->final_dim[env->i].y;
	x1 = env->final_dim[env->i + 1].x;
	y1 = env->final_dim[env->i + 1].y;
	env->s_x++;
}

void	low_limit(t_env *env)
{
	int x0;
	int x1;
	int y0;
	int y1;

	x0 = env->final_dim[env->i].x;
	y0 = env->final_dim[env->i].y;
	x1 = env->final_dim[env->i + env->map_l].x;
	y1 = env->final_dim[env->i + env->map_l].y;
}