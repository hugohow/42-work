/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:33:25 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 13:34:40 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrjoin(wchar_t const *str1, wchar_t const *str2)
{
	wchar_t	*new_str;
	size_t	i;
	size_t	j;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	new_str = (wchar_t *)malloc((ft_wcslen(str1) + ft_wcslen(str2) + 1) * sizeof(wchar_t));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (str1[++i] != L'\0')
		new_str[i] = str1[i];
	j = 0;
	while (str2[j] != L'\0')
		new_str[i++] = str2[j++];
	new_str[i] = L'\0';
	return (new_str);
}
