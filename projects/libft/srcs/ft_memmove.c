/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:00:20 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:35:39 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	long i;
	unsigned char *scr_cpy;

	scr_cpy = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	i = (dst < src) ? 0 : (long)(len - 1);
	while (i < (long)len && scr_cpy[i])
	{
		if (dst < src)
			((unsigned char *)dst)[i] = scr_cpy[i++];
		else
			((unsigned char *)dst)[i] = scr_cpy[i--];
	}
	return (dst);
}