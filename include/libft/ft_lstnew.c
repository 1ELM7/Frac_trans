/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:43:02 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/20 21:55:49 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(1 * (sizeof(t_list)));
	if (!new)
		return (T_NULL);
	new->content = content;
	new->next = T_NULL;
	return (new);
}
