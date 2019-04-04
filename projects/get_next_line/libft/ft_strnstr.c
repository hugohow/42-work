/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:04:27 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:49:53 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	to_find_len;
	size_t	i;
	size_t	j;

	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0)
		return (char *)(str);
	i = -1;
	while (str[++i] && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] && to_find[j] &&
				str[i + j] == to_find[j] && i + j < len)
				j++;
			if (to_find[j] == '\0')
				return (char *)(str + i);
		}
	}
	return (NULL);
}
