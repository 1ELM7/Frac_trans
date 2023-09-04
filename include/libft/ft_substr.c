/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:29:24 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/24 19:34:00 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ends;
	unsigned int	i;
	size_t			j;

	i = 0;
	if (!s)
		return (T_NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	else if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	ends = malloc((len + 1) * sizeof(char));
	if (!ends)
		return (T_NULL);
	i = start;
	j = 0;
	while (s[i] && (j < len))
	{
		ends[j] = s[i];
		i++;
		j++;
	}
	ends[j] = '\0';
	return (ends);
}
