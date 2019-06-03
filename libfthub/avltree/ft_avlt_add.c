/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlt_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:44:31 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 12:38:12 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

t_node_avlt	*ft_avlt_add(t_node_avlt **p_root, void *content, \
	size_t content_size, int (*cmp)(t_node_avlt *, t_node_avlt *))
{
	t_node_avlt *node;

	node = ft_avlt_create(content, content_size);
	if (node == NULL)
		return (NULL);
	if (*p_root == NULL)
		*p_root = node;
	else
		node = ft_avlt_insert(p_root, node, cmp);
	if (node == NULL)
		return (NULL);
	return (node);
}
