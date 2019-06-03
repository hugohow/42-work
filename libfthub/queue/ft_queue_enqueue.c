/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_enqueue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:47:04 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 13:10:17 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	ft_queue_enqueue(t_queue **p_queue, void const *content, size_t size)
{
	t_list *node;

	node = ft_lstnew(content, size);
	if (node == NULL || p_queue == NULL || *p_queue == NULL)
		return (0);
	if (((*p_queue)->tail) == NULL)
	{
		(*p_queue)->tail = node;
		(*p_queue)->head = (*p_queue)->tail;
	}
	else
	{
		((*p_queue)->tail)->next = node;
		(*p_queue)->tail = node;
	}
	(*p_queue)->size = (*p_queue)->size + 1;
	return (1);
}
