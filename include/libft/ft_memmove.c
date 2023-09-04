/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:34:25 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/20 19:00:21 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*dest2;
	char		*src2;

	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	if (!dest && !src)
		return (T_NULL);
	if (dest2 > src2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			dest2[i] = src2[i];
			i--;
		}
		return (dest2);
	}
	while (i < (int)n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
