/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlt_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:37:07 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 12:41:44 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

t_node_avlt	*ft_avlt_create(void *content, size_t content_size)
{
	t_node_avlt	*node;
	void		*content_cpy;

	node = (t_node_avlt *)ft_memalloc(sizeof(t_node_avlt));
	if (node == NULL)
		return (NULL);
	content_cpy = (void *)ft_memalloc(content_size);
	if (content_cpy == NULL)
	{
		ft_memdel((void *)&node);
		return (NULL);
	}
	ft_memcpy(content_cpy, content, content_size);
	node->content = content_cpy;
	node->content_size = content_size;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
