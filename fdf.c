/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:07:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/19 16:31:29 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_env	env;

	env.map_loc = av[1];
	env.map_h = 0;
	env.map_l = 0;
	env.translation = 1;
	env.y = 0;
	env.angle = 7.37;
	env.altitude = 1;
	env.scale = 30;
	env.mousex = 0;
	env.mousey = 0;
	if (ac == 2)
	{
		map_size(&env, env.map_loc);
		size_map(&env, env.map_loc);
		parse_map(&env, env.map_loc);
		three_point(&env);
		window_init(&env);
	}
	else
	{
		ft_printf("Too many arguments");
	}
}

int	error_mes(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}

void	free_tab(t_env *env)
{
	int	y;

	y = 0;
	while (y < env->map_h)
	{
		free(env->final_map[y]);
		y++;
	}
	free(env->final_map);
}

void	free_tab1(t_env *env)
{
	free(env->init_dim);
	free(env->mlx);
}
