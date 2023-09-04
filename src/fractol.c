/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:50:33 by jmendez           #+#    #+#             */
/*   Updated: 2023/03/17 19:14:11 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res >= 0)
		return (res + res2);
	else
		return (res + -res2);
}

static int	open_win(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, SIZE, SIZE, "Frac_trans");
	data->zoom = 1.0;
	data->abs = 0.0;
	data->ord = 0.0;
	data->flag = 8;
	draw(data);
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, mlx_close, data);
	mlx_hook(data->mlx_win, 2, 1L, key_hook, data);
	mlx_loop(data->mlx);
	return (0);
}

static int	error_input(void)
{
	ft_printf("During your execution you can enter :\n");
	ft_printf("   - mandelbrot\n   - julia\n   - bonus\n");
	ft_printf("\nYou can also enter :\n");
	ft_printf("   - julia [desired real] [desired imaginary]\n");
	ft_printf("You can try again by restarting the program !\n");
	return (0);
}

static void	bis_main(char **argv, t_data *data)
{
	if (!ft_strncmp(argv[1], "julia", 5))
	{
		data->r = JU_R;
		data->i = JU_I;
		data->frac = 0;
	}
	else if (!ft_strncmp(argv[1], "mandelbrot", 10))
	{
		data->r = 0.0;
		data->i = 0.0;
		data->frac = 1;
	}
	else if (!ft_strncmp(argv[1], "bonus", 5))
		data->frac = 2;
	else
		data->frac = 666;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		data.r = ft_atof(argv[2]);
		data.i = ft_atof(argv[3]);
		data.frac = 0;
	}
	else if (argc == 2)
	{
		bis_main(argv, &data);
		if (data.frac == 666)
			return (error_input());
	}
	else
		return (error_input());
	open_win(&data);
}
