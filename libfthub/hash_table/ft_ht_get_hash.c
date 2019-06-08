/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_get_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 22:38:20 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/08 22:57:02 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

int	ft_ht_get_hash(const char *str, size_t size)
{
	unsigned long long	key;
	int 				i;

	i = 0;
	key = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		key += str[i] * i;
		i++;
	}
	key = key % size;
	return ((int)key);
}