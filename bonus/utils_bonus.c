/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:19:32 by jmendez           #+#    #+#             */
/*   Updated: 2023/03/17 19:12:20 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_bonus/fractol_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

long double	get_pixel_coordinate(int pix, t_data *data, float move)
{
	long double	z;

	z = (4 * (long double)pix - 2 * SIZE) / SIZE;
	z *= data->zoom;
	z += move;
	return (z);
}

long double	get_pixel_coo(int pix, t_data *data)
{
	long double	z;

	z = (4 * (long double)pix - 2 * SIZE) / SIZE;
	z *= data->zoom;
	return (z);
}

int	mlx_close(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	exit(0);
	return (0);
}
