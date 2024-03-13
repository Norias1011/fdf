/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:07:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/13 14:26:30 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, void *param)
{
	int	i;

	i = 1 * (int)param;
	ft_putnbr_fd(key, 1);
	return (0);
}
* /

	int main(int ac, char *av[])
{
	t_env	env;

	env.map_loc = av[1];
	env.map_h = 0;
	env.map_l = 0;
	env.y = 0;
	env.angle = 7.37;
	env.altitude = 1;
	env.scale = 30;
	if (ac == 2)
	{
		map_size(&env, env.map_loc);
		size_map(&env, env.map_loc);
		parse_map(&env, env.map_loc);
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

/*int main()
{
	void    *mlx_ptr;
	void    *win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FDF test");
	if (win_ptr == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}*/