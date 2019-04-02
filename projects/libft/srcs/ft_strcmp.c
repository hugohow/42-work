/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:00:53 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:38:38 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (*(s1 + i) && *(s2 + i) && *(s1 + i) == *(s2 + i))
		i++;
	if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
		return (0);
	return ((int)((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i)));
}
