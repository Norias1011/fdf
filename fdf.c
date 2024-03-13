/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:07:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/03/12 18:31:01 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	ft_putnbr_fd(int n, int fd)
{
	long	c;

	if (fd == 0)
		return ;
	c = n;
	if (c < 0)
	{
		write(fd, "-", 1);
		c = c * -1;
	}
	if (c >= 10)
	{
		ft_putnbr_fd(c / 10, fd);
		c = c % 10;
	}
	if (c < 10)
	{
		c = c + '0';
		write(fd, &c, 1);
	}
}

int deal_key(int key, void *param)
{
    int i = 1 * (int)param;
    ft_putnbr_fd(key, 1);
    return (0);
}*/

int main()
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
}