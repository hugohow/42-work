/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:04:28 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/14 20:21:16 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_ht_get(t_ht *hash_table, const char *key)
{
	size_t i;

	if (hash_table == NULL)
		return (NULL);
	i = 0;
	while (hash_table->table[i] && 
		ft_strcmp((hash_table->table[i])->key, key) != 0)
		i++;
	if (hash_table->table[i] == 0)
		return (NULL);
	return ((hash_table->table[i])->datum);
}