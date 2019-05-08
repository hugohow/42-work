/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlt_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:49:16 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/07 17:40:44 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

t_node_avlt	*ft_avlt_insert(t_node_avlt **p_root, t_node_avlt *node, int (*cmp)(t_node_avlt *, t_node_avlt *))
{
	if (p_root == NULL || *p_root == NULL || node == NULL)
		return (NULL);
	
	if (cmp(*p_root, node) < 0)
	{
		(*p_root)->height = (*p_root)->height + 1;
		if ((*p_root)->right == NULL)
		{
			(*p_root)->right = node;
			return (node);
		}
		return (ft_avlt_insert(&((*p_root)->right), node, cmp));
	}
	else
	{
		(*p_root)->height = (*p_root)->height - 1;
		if ((*p_root)->left == NULL)
		{
			(*p_root)->left = node;
			return (node);
		}
		return (ft_avlt_insert(&((*p_root)->left), node, cmp));
	}
}