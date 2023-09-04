/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:12:12 by jmendez           #+#    #+#             */
/*   Updated: 2023/03/17 19:14:24 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	key_hook_color(int key_code, t_data *data)
{
	if (key_code == K_NUM_0)
		data->flag = 0;
	else if (key_code == K_NUM_1)
		data->flag = 1;
	else if (key_code == K_NUM_2)
		data->flag = 2;
	else if (key_code == K_NUM_3)
		data->flag = 3;
	else if (key_code == K_NUM_4)
		data->flag = 4;
	else if (key_code == K_NUM_5)
		data->flag = 5;
	else if (key_code == K_NUM_6)
		data->flag = 6;
	else if (key_code == K_NUM_7)
		data->flag = 7;
	else if (key_code == K_NUM_8)
		data->flag = 8;
	else if (key_code == K_NUM_9)
		data->flag = 9;
	draw(data);
}

static void	key_hook_value_bis(int key_code, t_data *data)
{
	if (key_code == K_DIGIT_5)
	{
		data->r = JU5_R;
		data->i = JU5_I;
		data->frac = 0;
	}
	else if (key_code == K_DIGIT_6)
	{
		data->r = JU6_R;
		data->i = JU6_I;
		data->frac = 0;
	}
	else if (key_code == K_DIGIT_7)
	{
		data->r = JU7_R;
		data->i = JU7_I;
		data->frac = 0;
	}
	else if (key_code == K_DIGIT_8)
	{
		data->r = JU_R;
		data->i = JU_I;
		data->frac = 0;
	}
	draw(data);
}

static void	key_hook_value(int key_code, t_data *data)
{
	if (key_code == K_DIGIT_1)
	{
		data->r = JU1_R;
		data->i = JU1_I;
		data->frac = 0;
	}
	else if (key_code == K_DIGIT_2)
	{
		data->r = JU2_R;
		data->i = JU2_I;
		data->frac = 0;
	}
	else if (key_code == K_DIGIT_3)
	{
		data->r = JU3_R;
		data->i = JU3_I;
		data->frac = 0;
	}
	else if (key_code == K_DIGIT_4)
	{
		data->r = JU4_R;
		data->i = JU4_I;
		data->frac = 0;
	}
	key_hook_value_bis(key_code, data);
}

int	key_hook(int key_code, t_data *data)
{
	if (key_code == K_ESC)
		mlx_close(data);
	else if (key_code == K_NUM_MINUS)
		data->zoom *= 1.5;
	else if (key_code == K_NUM_PLUS)
		data->zoom /= 1.5;
	else if (key_code == K_UP)
		data->abs -= 0.5;
	else if (key_code == K_DOWN)
		data->abs += 0.5;
	else if (key_code == K_LEFT)
		data->ord -= 0.5;
	else if (key_code == K_RIGHT)
		data->ord += 0.5;
	else if (key_code == K_J)
		data->frac = 0;
	else if (key_code == K_M)
		data->frac = 1;
	else if (key_code == K_B)
		data->frac = 2;
	key_hook_value(key_code, data);
	key_hook_color(key_code, data);
	draw(data);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_data *data)
{
	long double	tx;
	long double	ty;

	tx = get_pixel_coordinate(x, data, data->ord);
	ty = get_pixel_coordinate(y, data, data->abs);
	if (code == 5)
	{
		data->zoom *= 1.2;
		data->ord = (tx - get_pixel_coo(x, data));
		data->abs = (ty - get_pixel_coo(y, data));
	}
	else if (code == 4)
	{
		data->zoom *= 0.8;
		data->ord = (tx - get_pixel_coo(x, data));
		data->abs = (ty - get_pixel_coo(y, data));
	}
	draw(data);
	return (0);
}
