/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:43:24 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/13 21:43:38 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	len2;

	if ((!dest && size == 0) || (!src && size == 0))
		return (0);
	i = 0;
	len = ft_strlen(dest);
	j = len;
	len2 = ft_strlen((char *)src);
	if (size < len)
		return (len2 + size);
	if (size == 0)
		return (len + len2);
	while (src[i] && i + j < size - 1)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = 0;
	return (len + len2);
}
