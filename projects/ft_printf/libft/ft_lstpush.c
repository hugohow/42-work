/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:29:43 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/11 10:43:43 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list **head, void const *content, size_t content_size)
{
	t_list	*node;

	node = ft_lstnew(content, content_size);
	if (node)
	{
		node->next = *head;
		*head = node;
	}
	return (node);
}
