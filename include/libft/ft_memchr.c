/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:39:52 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/13 21:40:08 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*src;

	src = (char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (char)c)
		{
			return (src + i);
		}
		i++;
	}
	return (T_NULL);
}
