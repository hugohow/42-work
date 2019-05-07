/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:45:06 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/07 13:19:12 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void free_node(t_node_bt *node)
{
	if (node)
	{
		ft_memdel((void *)(&(node->content)));
		node->content_size = 0;
		ft_memdel((void *)(&node));
	}
}

void	ft_bt_free(t_node_bt **p_root)
{
	if (p_root == NULL || *p_root == NULL)
		return ;
	ft_bt_apply_postorder(*p_root, &free_node);
	*p_root = NULL;
}