/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:45:26 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/20 19:04:33 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *chr, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!s && len == 0))
		return (T_NULL);
	if (chr[0] == 0)
		return ((char *)s);
	i = 0;
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] == chr[j] && (i + j) < len)
		{
			if (s[i + j] == 0 && chr[j] == 0)
				return ((char *)&s[i]);
			j++;
		}
		if (chr[j] == 0)
			return ((char *)&s[i]);
		i++;
	}
	return (T_NULL);
}
