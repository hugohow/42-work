/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:13:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 18:42:19 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	size_t i;
	size_t j;
	size_t str_len;

	if (str == NULL)
		return (NULL);
	i = 0;
	str_len = ft_strlen(str);
	if (str_len == 0)
		return ((char *)str);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (i == str_len)
		return ("");
	j = str_len - 1;
	while (str[j] && (str[j] == ' ' || str[j] == '\t' || str[j] == '\n'))
		j--;
	return (ft_strsub(str, i, j - i + 1));
}
