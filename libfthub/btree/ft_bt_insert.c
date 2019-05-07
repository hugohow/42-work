/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:49:16 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/07 12:50:44 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_node_bt	*ft_bt_insert(t_node_bt **p_root, t_node_bt *node, int (*cmp)(t_node_bt *, t_node_bt *))
{
	if (p_root == NULL || *p_root == NULL || node == NULL)
		return (NULL);
	
	if (cmp(*p_root, node) < 0)
	{
		if ((*p_root)->right == NULL)
		{
			(*p_root)->right = node;
			return (node);
		}
		return (ft_bt_insert(&((*p_root)->right), node, cmp));
	}
	if ((*p_root)->left == NULL)
	{
		(*p_root)->left = node;
		return (node);
	}
	return (ft_bt_insert(&((*p_root)->left), node, cmp));
}