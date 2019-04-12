/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:13:28 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 18:46:11 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *element;

	if (lst == NULL)
		return (NULL);
	element = f(lst);
	new = element;
	while (lst->next)
	{
		lst = lst->next;
		if (f(lst) == NULL)
			return (NULL);
		element->next = f(lst);
		element = element->next;
	}
	return (new);
}
