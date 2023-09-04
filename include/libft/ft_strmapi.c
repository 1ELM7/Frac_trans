/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:19:01 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/21 22:04:14 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*end;

	if (!s)
		return (T_NULL);
	i = 0;
	len = ft_strlen(s);
	end = malloc((len + 1) * sizeof(char));
	if (!end)
		return (T_NULL);
	while (s[i] != '\0')
	{
		end[i] = f(i, s[i]);
		i++;
	}
	end[i] = '\0';
	return (end);
}
