/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_separate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:00:29 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/25 13:08:34 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*get_word(const char *str, char c)
{
	char		*word;
	size_t		j;

	if (!(word = (char *)ft_memalloc((strlen(str) + 1) * sizeof(*word))))
		return (NULL);
	j = 0;
	while (str[j] && str[j] != c)
	{
		word[j] = str[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}


char			**ft_str_separate(char const *str, char c)
{
	char		**list;
	char		*word;
	int			i;
	size_t		k;

	if (str == NULL)
		return (NULL);
	if (!(list = (char **)ft_memalloc((strlen(str) + 3) * sizeof(char *))))
		return (NULL);
	i = 0;
	k = 0;
	if (ft_strlen(str) == 0)
	{
		list[k++] = strdup("");
		list[k++] = 0;
		return (list);
	}
	if (str[0] == c)
		list[k++] = strdup("");
	while (str[i])
	{
		if (str[i] != c)
		{
			word = get_word(str + i, c);
			list[k++] = word;
			i += strlen(word) - 1;
		}
		i++;
	}
	if (i > 1 && str[i - 1] == c)
		list[k++] = strdup("");	
	list[k++] = 0;
	return (list);
}