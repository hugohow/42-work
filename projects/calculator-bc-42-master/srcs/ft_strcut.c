/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:18:26 by hhow-cho          #+#    #+#             */
/*   Updated: 2018/11/11 11:40:58 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int		take_integer_len(char *str)
{
	int len;

	len = 0;
	while (str[len] >= '0' && str[len] <= '9' && str[len])
	{
		len++;
	}
	return (len);
}

char	*cut(char *str, int len)
{
	char	*cut_str;
	int		i;

	cut_str = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (cut_str == NULL)
		return (cut_str);
	i = 0;
	while (i < len)
	{
		cut_str[i] = str[i];
		i++;
	}
	cut_str[i] = '\0';
	return (cut_str);
}

int		len_cut(char *str)
{
	int count_parentheses;
	int i;

	count_parentheses = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			count_parentheses++;
		if (str[i] == ')' && count_parentheses == 0)
			return (i);
		if (str[i] == ')' && count_parentheses != 0)
			count_parentheses--;
		i++;
	}
	return (0);
}
