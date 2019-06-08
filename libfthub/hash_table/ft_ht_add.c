/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:57:51 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/08 23:08:01 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

static t_node_ht	*ft_create_node(const char *key, void *datum)
{
	t_node_ht *node;

	node = (t_node_ht *)ft_memalloc(sizeof(t_node_ht));
	if (node == NULL)
		return (NULL);
	node->key = ft_strdup(key);
	node->datum = ft_strdup(datum);
	node->next = NULL;
	return (node);
}

t_node_ht			*ft_ht_add(t_ht *hash_table, const char *key, void *datum)
{
	int			index;
	t_node_ht	*node;

	if (hash_table == NULL)
		return (NULL);
	index = ft_ht_get_hash(key, hash_table->size);
	node = hash_table->list[index];
	if (node == NULL)
	{
		node = ft_create_node(key, datum);
		hash_table->list[index] = node;
	}
	else
	{
		while (node->next)
			node = node->next;
		node->next = ft_create_node(key, datum);
		node = node->next;
	}
	return (node);
}
