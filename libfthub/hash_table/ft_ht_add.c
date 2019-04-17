/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:57:51 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/17 17:39:13 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

static t_node_ht	*ft_create_node(const char *key, void *datum)
{
	t_node_ht *node;

	node = (t_node_ht *)malloc(sizeof(t_node_ht));
	if (node == NULL)
		return (NULL);
	node->key = key;
	node->datum = datum;
	node->next = NULL;
	return (node);
}

t_node_ht			*ft_ht_add(t_ht *hash_table, const char *key, void *datum)
{
	size_t		index;
	t_node_ht	*node;

	if (hash_table == NULL)
		return (NULL);
	index = 0;
	while (hash_table->table[index] != NULL &&
		ft_strcmp((hash_table->table[index])->key, key) != 0)
		index++;
	if (hash_table->table[index] == NULL)
	{
		node = ft_create_node(key, datum);
		hash_table->table[index] = node;
		index++;
		hash_table->table[index] = 0;
		return (node);
	}
	else
	{
		node = hash_table->table[index];
		while (node->next)
			node = node->next;
		node->next = ft_create_node(key, datum);
		return (node->next);
	}
}
