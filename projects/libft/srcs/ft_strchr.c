/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:00:44 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:37:59 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if ((char)c == '\0')
		return (char *)(s + ft_strlen(s));
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return (char *)(s + i);
		i++;
	}
	return (NULL);
}
