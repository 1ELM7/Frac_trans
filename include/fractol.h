/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:52:05 by jmendez           #+#    #+#             */
/*   Updated: 2023/03/02 18:16:37 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <math.h>
# include "color.h"
# include "keys.h"
# include "coordonates.h"

# define SIZE 1001

typedef struct s_data {
	void		*img;
	void		*mlx;
	char		*addr;
	void		*win;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	long double	i;
	long double	r;
	int			x;
	int			y;
	long double	zoom;
	void		*mlx_win;
	long double	abs;
	long double	ord;
	int			frac;
	int			flag;
}				t_data;

//from keys.c
int			key_hook(int key_code, t_data *data);
int			mouse_hook(int code, int x, int y, t_data *data);

//from draw_fract.c
void		julia(t_data *data, int i, int j);
void		mandelbrot(t_data *data, int i, int j);
void		burning_ship(t_data *data, int i, int j);
void		draw(t_data *data);

//from dispatch_colors.c
int			put_color(t_data *data, int iter);

//from colors.c
int			omni_flag(int i);
int			transmasc_flag(int i);
int			anar_flag(int i);
int			violet(int i);
int			black_and_white(int i);

//from colors.c
int			trans_flag(int i);
int			nb_flag(int i);
int			pan_flag(int i);
int			lgbt_flag(int i);
int			bi_flag(int i);

//from utils.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
long double	get_pixel_coordinate(int pix, t_data *data, float move);
long double	get_pixel_coo(int pix, t_data *data);
int			mlx_close(t_data *data);

#endif
