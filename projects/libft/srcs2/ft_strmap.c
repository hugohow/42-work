/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:12:23 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 18:11:04 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*new_str;
	size_t	i;

	if (str == NULL)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new_str[i] = (*f)(str[i]);
	new_str[i] = '\0';
	return (new_str);
}
