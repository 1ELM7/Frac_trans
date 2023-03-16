/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:45:48 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/13 21:45:59 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*calloc;
	size_t	i;

	i = 0;
	if (size >= 65536 || nmemb >= 65536)
		return (NULL);
	calloc = malloc(size * nmemb);
	if (!calloc)
		return (NULL);
	while (i < nmemb * size)
	{
		calloc[i] = 0;
		i++;
	}
	return ((void *)calloc);
}
