/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:43:10 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/30 20:05:01 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const c, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(set) - 1;
	while (i <= len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trim_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if ((ft_check_set(s1[i], set) == 0))
			break ;
		i ++;
	}
	return (i);
}

static int	ft_trim_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while ((ft_check_set(s1[i], set) == 1))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (T_NULL);
	i = ft_trim_start(s1, set);
	j = ft_trim_end(s1, set);
	str = ft_substr(s1, i, j - i + 1);
	return (str);
}
