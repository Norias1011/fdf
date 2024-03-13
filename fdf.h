/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:36:38 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/13 16:03:09 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct initial_dimension
{
	int			x;
	int			y;
	int			z;
}				t_init;

typedef struct final_dimension
{
	int			x;
	int			y;
}				t_final;

typedef struct pixel_coordinate
{
	int			dx;
	int			dy;
}				t_pixcor;

typedef struct s_envir
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*address;
	char		*map_loc;
	int			**final_map;
	int			map_h;
	int			map_l;
	int			x;
	int			y;
	int			altitude;
	int			scale;
	int			bits_by_pixel;
	int			line_length;
	int			endian;
	float		angle;
	t_init		*init_dim;
	t_final		*final_dim;
	t_pixcor	*pixel_coor;
}				t_env;

/* fdf.c functions */
int				error_mes(char *error_message);

/* mapcheck functions */

void			map_size(t_envi *env, char *maps);
void			size_map(t_env *env, char *maps);
void			parse_map(t_env *env, char *file);

/* dimension.c functions */

void			three_point(t_env *env);
void			two_point(t_env *env);

/* initwin.c functions */

int				window_init(t_env *env);

#endif