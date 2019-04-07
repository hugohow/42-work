/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:13:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/07 13:56:19 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_escapable_fttrim(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int count_len_fttrim(const char *str)
{
	int i;
	int len;

	i = 0;
  len = 0;
	while (str[i] && is_escapable_fttrim(str[i]))
		i++;
	while (str[i])
	{
		i++;
		len++;
  }
  i--;
	while (str[i] && is_escapable_fttrim(str[i]))
	{
		i--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *str)
{
	int i;
	int k;
	int len;
	char *output;

  if (str == NULL)
    return (NULL);
	len = count_len_fttrim(str);
	if (len <= 0)
		return (ft_strdup(""));
	output = (char *)malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] && is_escapable_fttrim(str[i]))
		i++;
	while (k < len)
	{
		output[k] = str[i];
		k++;
    	i++;
	}
	output[k] = '\0';
	return (output);
}