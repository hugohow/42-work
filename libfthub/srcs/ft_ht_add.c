/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:57:51 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/14 20:24:09 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node_ht *ft_ht_add(t_ht *hash_table, const char *key, void *datum)
{
	size_t index;
	t_node_ht *node;

	if (hash_table == NULL)
		return (NULL);
	index = 0;
	while (hash_table->table[index] != NULL &&
		ft_strcmp((hash_table->table[index])->key, key) != 0)
		index++;
	if (hash_table->table[index] == NULL)
	{
		node = (t_node_ht *)malloc(sizeof(t_node_ht));
		if (node == NULL)
			return (NULL);
		node->key = key;
		node->datum = datum;
		node->next = NULL;
		hash_table->table[index] = node;
		index++;
		hash_table->table[index] = 0;
	}
	node = hash_table->table[index];
	while (node->next)
		node = node->next;
	
	node->next = (t_node_ht *)malloc(sizeof(t_node_ht));
	if (node->next == NULL)
		return (NULL);
	(node->next)->key = key;
	(node->next)->datum = datum;
	(node->next)->next = NULL;
	return (node->next);
}
