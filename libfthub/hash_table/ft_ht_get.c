/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:04:28 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/08 22:52:18 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

t_node_ht		*ft_ht_get(t_ht *hash_table, const char *key)
{
	int			index;
	t_node_ht	*node;

	if (hash_table == NULL)
		return (NULL);
	index = ft_ht_get_hash(key, hash_table->size);
	node = hash_table->list[index];
	while (node)
	{
		if (ft_strcmp(node->key, key) == 0)
			break;
		node = node->next;
	}
	return (node);
}
