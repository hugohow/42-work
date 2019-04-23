/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:56:50 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/23 16:09:35 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_r(const char *src, char *dst)
{
	int		i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	while (i >= 0)
	{
		dst[len_src + i] = dst[i];
		i--;
	}
	i = 0;
	while (i < (int)len_src)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
