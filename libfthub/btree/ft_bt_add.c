/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:44:31 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/07 12:43:04 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_node_bt	*ft_bt_add(t_node_bt **p_root, void *content, size_t content_size, int (*cmp)(t_node_bt *, t_node_bt *))
{
	t_node_bt *node;

	node = ft_bt_create(content, content_size);
	if (node == NULL)
		return (NULL);
	
	if (ft_bt_insert(p_root, node, cmp) == NULL)
		return (NULL);
	return (node);
}