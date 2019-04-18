/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:34:08 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/11 10:42:46 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **p_head, void (*del)(void *, size_t))
{
	t_list	*node;

	node = *p_head;
	if (node)
	{
		*p_head = node->next;
		ft_lstdelone(&node, del);
	}
	return (*p_head);
}
