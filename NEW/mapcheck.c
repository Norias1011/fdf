/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:51:21 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/14 18:09:16 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_size(t_env *env, char *maps)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(maps, O_RDONLY);
	if (fd < 0)
		error_mes("Map Error");
	line = get_next_line(fd);
	if (!line)
		error_mes("Map Empty");
	tab = ft_split(line, ' ');
	while (tab[env->map_l])
	{
		free(tab[env->map_l]);
		env->map_l++;
	}
	while (line)
	{
		free(line);
		env->map_h++;
		line = get_next_line(fd);
	}
	free(line);
	free(tab);
	close(fd);
}

void	size_map(t_env *env, char *maps)
{
	int		fd;
	char	*line;
	char	**tab;
	int		x;

	fd = open(maps, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line);
		x = 0;
		while (tab[x])
		{
			free(tab[x]);
			x++;
		}
		free(tab);
		if (x < env->map_l || x > env->map_l)
			error_mes("Map format error");
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	parse_map(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	env->final_map = malloc(sizeof(int *) * env->map_h);
	if (!env->final_map)
		error_mes("Error Malloc");
	while (env->y < env->map_h)
	{
		env->final_map[env->y] = malloc(sizeof(int) * env->map_l);
		if (!env->final_map[env->y])
			error_mes("Error Malloc");
		line = get_next_line(fd);
		tab = ft_split(line, ' ');
		free(line);
		env->x = -1;
		while (++env->y < env->map_l)
		{
			env->final_map[env->y][env->x] = ft_atoi(tab[env->x]);
			free(tab[env->x]);
		}
		env->y++;
		free(tab);
	}
}
