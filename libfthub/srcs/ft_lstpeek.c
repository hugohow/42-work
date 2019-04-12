/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpeek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:33:14 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/11 10:43:30 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpeek(t_list *head, int (*cmp)(t_list *elem1, t_list *elem2))
{
	t_list *node;
	t_list *node_peek;

	node_peek = head;
	node = head;
	while (node)
	{
		if (cmp(node, head) > 0)
			node_peek = node;
		node = node->next;
	}
	return (node_peek);
}
