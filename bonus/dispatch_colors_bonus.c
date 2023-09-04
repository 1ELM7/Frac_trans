/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_colors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:26:15 by jmendez           #+#    #+#             */
/*   Updated: 2023/03/17 19:11:06 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_bonus/fractol_bonus.h"

int	put_color(t_data *data, int iter)
{
	int	x;

	if (data->flag == 0)
		x = trans_flag(iter);
	else if (data->flag == 1)
		x = nb_flag(iter);
	else if (data->flag == 2)
		x = pan_flag(iter);
	else if (data->flag == 3)
		x = lgbt_flag(iter);
	else if (data->flag == 4)
		x = bi_flag(iter);
	else if (data->flag == 5)
		x = omni_flag(iter);
	else if (data->flag == 6)
		x = transmasc_flag(iter);
	else if (data->flag == 7)
		x = anar_flag(iter);
	else if (data->flag == 8)
		x = violet(iter);
	else if (data->flag == 9)
		x = black_and_white(iter);
	return (x);
}
