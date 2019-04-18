/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:04:08 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/10 20:30:22 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len1;

	len1 = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[len1 + i] = s2[i];
		i++;
	}
	s1[len1 + i] = '\0';
	return (s1);
}
