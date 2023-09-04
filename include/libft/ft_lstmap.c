/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:00:47 by jmendez           #+#    #+#             */
/*   Updated: 2022/10/20 23:18:17 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*l;

	if (!lst && !del)
		return (T_NULL);
	l = T_NULL;
	while (lst != T_NULL)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&l, del);
			return (T_NULL);
		}
		ft_lstadd_back(&l, tmp);
		lst = lst->next;
	}
	return (l);
}
