/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:55:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/17 16:03:44 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

t_ht			*ft_ht_create(size_t size)
{
	t_ht *hash_table;

	hash_table = (t_ht *)malloc(sizeof(t_ht));
	if (hash_table == NULL)
		return (NULL);
	hash_table->size = size;
	hash_table->table = (t_node_ht **)malloc(size * sizeof(t_node_ht *));
	if (hash_table == NULL)
		return (NULL);
	hash_table->table[0] = 0;
	return (hash_table);
}
