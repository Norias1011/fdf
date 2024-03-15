/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:36:38 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/14 18:09:03 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
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
	int			s_x;
	int			s_y;
	int			incrx;
	int			incry;
	int			i;
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

void			map_size(t_env *env, char *maps);
void			size_map(t_env *env, char *maps);
void			parse_map(t_env *env, char *file);

/* dimension.c functions */

void			three_point(t_env *env);
void			two_point(t_env *env);

/* initwin.c functions */

int				window_init(t_env *env);
int				render(t_env *env);

/* mapslimit.c functions */

void			limits(t_env *env);
void			no_limit(t_env *env);
void			right_limit(t_env *env);
void			low_limit(t_env *env);

/* draw.c functions */

void			draw_line(t_env *env, t_final point1, t_final point2);
void			put_line(t_env *env, int x, int y, int color);
void			draw_background(t_env *env);

#endif
