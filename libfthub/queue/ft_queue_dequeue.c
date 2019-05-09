/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_dequeue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:52:20 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 15:06:13 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	ft_queue_dequeue(t_queue **p_queue)
{
	t_list *node;

	if (p_queue == NULL || *p_queue == NULL)
		return (0);
	if ((*p_queue)->head == NULL || (*p_queue)->size == 0)
		return (0);
	node = (*p_queue)->head;
	(*p_queue)->head = ((*p_queue)->head)->next;
	if ((*p_queue)->size == 1)
		(*p_queue)->tail = (*p_queue)->head;
	(*p_queue)->size = (*p_queue)->size - 1;
	return (1);
}
