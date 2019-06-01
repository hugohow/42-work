/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:00:20 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/01 15:14:59 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	if (dst == src || len == 0)
		return (dst);
	i = dst > src ? (int)len - 1 : -1;
	if (dst > src)
	{
		while (i + 1 >= 1)
		{
			*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
			i--;
		}
	}
	else
	{
		while (++i < (int)len)
			*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
	}
	return (dst);
}
