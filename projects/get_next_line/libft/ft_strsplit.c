/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:12:49 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/04 16:46:39 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

char	*get_word(const char *str, char c)
{
	char	*word;
	size_t	j;

	word = malloc((strlen(str) + 1) * sizeof(char));
	j = 0;
	if (word == NULL)
		return (NULL);
	while (str[j] && str[j] != c)
	{
		word[j] = str[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_strsplit(char const *str, char c)
{
	char	**list;
	size_t	i;
	size_t	k;

	if (str == NULL)
		return (NULL);
	list = (char **)malloc((count_words(str, c) + 1) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			list[k++] = get_word(str + i, c);
			i += strlen(list[k-1]);
		}
		else
			i++;
	}
	list[k++] = 0;
	return (list);
}