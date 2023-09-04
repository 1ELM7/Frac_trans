/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:32:19 by jmendez           #+#    #+#             */
/*   Updated: 2023/03/17 19:13:27 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	trans_flag(int i)
{
	int	x;

	x = i % 5;
	if (x == 0)
		return (BLUE_TRANS);
	else if (x == 1)
		return (PINK_TRANS);
	else if (x == 2)
		return (WHITE);
	else if (x == 3)
		return (PINK_TRANS);
	else if (x == 4)
		return (BLUE_TRANS);
	return (0);
}

int	nb_flag(int i)
{
	int	x;

	x = i % 4;
	if (x == 0)
		return (YELLOW_NB);
	else if (x == 1)
		return (WHITE);
	else if (x == 2)
		return (PURPLE_NB);
	else if (x == 3)
		return (BLACK_NB);
	return (0);
}

int	pan_flag(int i)
{
	int	x;

	x = i % 3;
	if (x == 0)
		return (MAGENTA_PAN);
	else if (x == 1)
		return (YELLOW_PAN);
	else if (x == 2)
		return (CYAN_PAN);
	return (0);
}

int	lgbt_flag(int i)
{
	int	x;

	x = i % 6;
	if (x == 0)
		return (RED_LGBT);
	else if (x == 1)
		return (ORANGE_LGBT);
	else if (x == 2)
		return (YELLOW_LGBT);
	else if (x == 3)
		return (GREEN_LGBT);
	else if (x == 4)
		return (BLUE_LGBT);
	else if (x == 5)
		return (PURPLE_LGBT);
	return (0);
}

int	bi_flag(int i)
{
	int	x;

	x = i % 5;
	if (x == 0)
		return (PINK_BI);
	else if (x == 1)
		return (PINK_BI);
	else if (x == 2)
		return (PURPLE_BI);
	else if (x == 3)
		return (BLUE_BI);
	else if (x == 4)
		return (BLUE_BI);
	return (0);
}
