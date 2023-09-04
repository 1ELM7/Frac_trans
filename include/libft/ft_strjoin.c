/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:18:42 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/15 16:20:16 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlens(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	return (len1 + len2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (T_NULL);
	len = ft_strlens(s1, s2);
	tmp = malloc((len + 1));
	if (!tmp)
		return (T_NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		tmp[i + j] = s2[j];
		j++;
	}
	tmp[i + j] = '\0';
	return (tmp);
}
