/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:04:33 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/11 10:48:01 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if ((char)c == '\0')
		return (char *)(s + ft_strlen(s));
	if (ft_strlen(s) == 0)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (*(s + i) == (char)c)
			return (char *)(s + i);
		i--;
	}
	if (*s == (char)c)
		return (char *)s;
	return (NULL);
}
