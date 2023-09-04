/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:33:27 by jmendez           #+#    #+#             */
/*   Updated: 2023/03/17 19:10:46 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_bonus/fractol_bonus.h"

int	omni_flag(int i)
{
	int	x;

	x = i % 5;
	if (x == 0)
		return (L_PINK_OMNI);
	else if (x == 1)
		return (PINK_OMNI);
	else if (x == 2)
		return (D_PURPLE_OMNI);
	else if (x == 3)
		return (BLUE_OMNI);
	else if (x == 4)
		return (B_BLUE_OMNI);
	return (0);
}

int	transmasc_flag(int i)
{
	int	x;

	x = i % 7;
	if (x == 0)
		return (PINK_TRANSMASC);
	else if (x == 1)
		return (L_BLUE_TRANSMASC);
	else if (x == 2)
		return (S_BLUE_TRANSMASC);
	else if (x == 3)
		return (BLUE_TRANSMASC);
	else if (x == 4)
		return (S_BLUE_TRANSMASC);
	else if (x == 5)
		return (L_BLUE_TRANSMASC);
	else if (x == 6)
		return (PINK_TRANSMASC);
	return (0);
}

int	anar_flag(int i)
{
	int	x;

	x = i % 2;
	if (x == 0)
		return (RED_ANAR);
	else if (x == 1)
		return (BLACK_ANAR);
	return (0);
}

int	violet(int i)
{
	int	x;

	x = i % 9;
	if (x == 0)
		return (LAVENDER);
	else if (x == 1)
		return (PLUM);
	else if (x == 2)
		return (ORCHID);
	else if (x == 3)
		return (MEDIUM_ORCHID);
	else if (x == 4)
		return (MEDIUM_PURPLE);
	else if (x == 5)
		return (BLUE_VIOLET);
	else if (x == 6)
		return (DARK_VIOLET);
	else if (x == 7)
		return (PURPLE);
	else if (x == 8)
		return (INDIGO);
	return (0);
}

int	black_and_white(int i)
{
	int	x;

	x = i % 6;
	if (x == 0)
		return (WHITE);
	else if (x == 1)
		return (SILVER);
	else if (x == 2)
		return (GRAY);
	else if (x == 3)
		return (DIM_GRAY);
	else if (x == 4)
		return (BLACK_OLIVE);
	else if (x == 5)
		return (BLACK);
	return (0);
}
