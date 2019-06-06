/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlt_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:43:44 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 12:43:15 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

static void	free_node(t_node_avlt *node)
{
	if (node)
	{
		ft_memdel((void *)(&(node->content)));
		node->content_size = 0;
		ft_memdel((void *)(&node));
	}
}

void		ft_avlt_free(t_node_avlt **p_root)
{
	if (p_root == NULL || *p_root == NULL)
		return ;
	ft_avlt_apply_postorder(*p_root, &free_node);
	*p_root = NULL;
}
