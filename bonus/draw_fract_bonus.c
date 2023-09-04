/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:18:31 by jmendez           #+#    #+#             */
/*   Updated: 2023/03/17 19:11:36 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_bonus/fractol_bonus.h"

static void	frac(t_data *data, int i, int j)
{
	if (data->frac == 0)
		julia(data, i, j);
	else if (data->frac == 1)
		mandelbrot(data, i, j);
	else if (data->frac == 2)
		burning_ship(data, i, j);
}

void	julia(t_data *data, int i, int j)
{
	long double	x[2];
	long double	y;
	int			iter;
	int			max_iter;

	max_iter = 100;
	iter = 0;
	x[1] = get_pixel_coordinate(i, data, data->ord);
	y = get_pixel_coordinate(j, data, data->abs);
	while (iter != max_iter && (x[1] * x[1] + y * y) < 4)
	{
		x[0] = x[1] * x[1] - y * y + data->r;
		y = 2 * x[1] * y + data->i;
		x[1] = x[0];
		iter++;
	}
	if (iter == max_iter)
		my_mlx_pixel_put(data, i, j, 0);
	else
		my_mlx_pixel_put(data, i, j, put_color(data, iter));
}

void	mandelbrot(t_data *data, int i, int j)
{
	long double	x[2];
	long double	y;
	int			iter;
	int			max_iter;

	max_iter = 50;
	iter = 0;
	x[1] = 0.0;
	y = 0.0;
	data->r = get_pixel_coordinate(i, data, data->ord);
	data->i = get_pixel_coordinate(j, data, data->abs);
	while (iter != max_iter && (x[1] * x[1] + y * y) < 4.0)
	{
		x[0] = x[1] * x[1] - y * y + data->r;
		y = 2 * x[1] * y + data->i;
		x[1] = x[0];
		iter++;
	}
	if (iter == max_iter)
		my_mlx_pixel_put(data, i, j, 0);
	else
		my_mlx_pixel_put(data, i, j, put_color(data, iter));
}

void	burning_ship(t_data *data, int i, int j)
{
	long double	x[2];
	long double	y;
	int			iter;
	int			max_iter;

	max_iter = 50;
	iter = 0;
	x[1] = 0.0;
	y = 0.0;
	data->r = get_pixel_coordinate(i, data, data->ord);
	data->i = get_pixel_coordinate(j, data, data->abs);
	while (iter++ != max_iter && (x[1] * x[1] + y * y) < 4.0)
	{
		x[0] = x[1] * x[1] - y * y + data->r;
		y = 2 * x[1] * y + data->i;
		if (x[0] < 0)
			x[0] *= -1;
		if (y < 0)
			y *= -1;
		x[1] = x[0];
	}
	if (iter == max_iter)
		my_mlx_pixel_put(data, i, j, 0);
	else
		my_mlx_pixel_put(data, i, j, put_color(data, iter));
}

void	draw(t_data *data)
{
	int		x;
	int		y;

	data->img = mlx_new_image(data->mlx, SIZE, SIZE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	x = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			frac(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}
