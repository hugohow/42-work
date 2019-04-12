/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:34:53 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 13:40:02 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t const *str, unsigned int start, size_t len)
{
	wchar_t	*new_str;
	size_t	i;

	if (str == NULL)
		return (NULL);
	if (len + start > ft_wcslen(str))
		return (NULL);
	new_str = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));
	if (new_str == NULL)
		return (NULL);
	i = start;
	while (i - start != len)
	{
		new_str[i - start] = str[i];
		i++;
	}
	new_str[len] = L'\0';
	return (new_str);
}
