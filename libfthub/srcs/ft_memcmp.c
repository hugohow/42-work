/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:00:08 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/11 10:49:51 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*(char *)(s1 + i) != *(char *)(s2 + i))
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return ((int)(*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i)));
}
