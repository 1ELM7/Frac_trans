/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:20:04 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/30 20:05:53 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_in_str(long int n, int sign, long int len)
{
	long int		rest;
	char			*end;

	if (n == 0)
		len++;
	end = malloc((len + 1) * sizeof(char));
	if (n == 0)
		end[0] = '0';
	if (!end)
		return (T_NULL);
	end[len--] = '\0';
	while (n != 0)
	{
		rest = n % 10;
		n = n / 10;
		end[len] = rest + '0';
		len--;
	}
	if (sign == -1)
		end[0] = '-';
	return (end);
}

char	*ft_itoa(int num)
{
	long int		len;
	long int		tmp;
	long int		n;
	char			*end;
	int				sign;

	len = 0;
	sign = 1;
	n = (long int) num;
	if (n < 0)
	{
		len ++;
		n = -n;
		sign = -sign;
	}
	tmp = n;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	end = ft_in_str(n, sign, len);
	return (end);
}
