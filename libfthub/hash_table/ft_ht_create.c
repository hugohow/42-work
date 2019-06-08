/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:55:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/08 22:44:03 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

t_ht			*ft_ht_create(void)
{
	t_ht	*hash_table;

	hash_table = (t_ht *)ft_memalloc(sizeof(t_ht));
	if (hash_table == NULL)
		return (NULL);
	hash_table->size = CLUSTER_SIZE;
	hash_table->count = 0;
	hash_table->list = (t_node_ht **)ft_memalloc(\
		hash_table->size * sizeof(t_node_ht *));
	return (hash_table);
}
