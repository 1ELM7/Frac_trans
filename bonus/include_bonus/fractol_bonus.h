/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:52:05 by jmendez           #+#    #+#             */
/*   Updated: 2023/03/16 20:59:05 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../../include/libft/libft.h"
# include "../../include/ft_printf/ft_printf.h"
# include "../../include/mlx_linux/mlx.h"
# include "../../include/mlx_linux/mlx_int.h"
# include <math.h>
# include "color_bonus.h"
# include "keys_bonus.h"
# include "coordonates_bonus.h"

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

//from keys_bonus.c
int			key_hook(int key_code, t_data *data);
int			mouse_hook(int code, int x, int y, t_data *data);

//from draw_fract_bonus.c
void		julia(t_data *data, int i, int j);
void		mandelbrot(t_data *data, int i, int j);
void		burning_ship(t_data *data, int i, int j);
void		draw(t_data *data);

//from dispatch_colors_bonus.c
int			put_color(t_data *data, int iter);

//from colors_bonus.c
int			omni_flag(int i);
int			transmasc_flag(int i);
int			anar_flag(int i);
int			violet(int i);
int			black_and_white(int i);

//from colors_bonus.c
int			trans_flag(int i);
int			nb_flag(int i);
int			pan_flag(int i);
int			lgbt_flag(int i);
int			bi_flag(int i);

//from utils_bonus.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
long double	get_pixel_coordinate(int pix, t_data *data, float move);
long double	get_pixel_coo(int pix, t_data *data);
int			mlx_close(t_data *data);

#endif
