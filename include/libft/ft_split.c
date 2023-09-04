/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:03:49 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/30 19:47:41 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
			n++;
		}
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
	}
	return (n);
}

static int	ft_nb_char(const char *s, char c, int i)
{
	int	tot;

	tot = 0;
	while ((s[tot + i] != c) && (s[tot + i] != '\0'))
		tot++;
	return (tot);
}

static char	**ft_new_var(char const *s, char c, char **ends)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i] != '\0'))
		{
			ends[j] = ft_substr(s, i, ft_nb_char(s, c, i));
			if (!ends[j])
				return (T_NULL);
			i = i + ft_nb_char(s, c, i);
			j++;
		}
		while ((s[i] != '\0') && (s[i] == c))
			i++;
	}
	return (ends);
}

char	**ft_split(char const *s, char c)
{
	char	**ends;
	int		nb_words;

	if (!s)
		return (T_NULL);
	if (s[0] == '\0')
	{
		ends = malloc(sizeof(char *));
		ends[0] = T_NULL;
		return (ends);
	}
	nb_words = ft_nb_words(s, c);
	ends = malloc((nb_words + 1) * sizeof(char *));
	if (!ends)
		return (T_NULL);
	ends[nb_words] = T_NULL;
	ends = ft_new_var(s, c, ends);
	return (ends);
}
