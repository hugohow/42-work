/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackets_is_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:38:03 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/13 17:39:32 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char brackets[] =
{
	'{',
	'}',
	'[',
	']',
	'(',
	')',
	'"',
	'"',
	39,
	39,
	0
};

int which_bracket(char c)
{
	int i;

	i = 0;
	while(brackets[i])
	{
		if (brackets[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int ft_find_closing(char *str, char closing, size_t len)
{
	size_t i;
	char opening;
	int count;

	i = 1;
	opening = str[0];
	count = 0;
	while (i < len)
	{
		if (str[i] == closing)
		{
			if (count == 0)
				return (i);
			else
				count--;
		}
		if (str[i] == opening)
			count++;
		i++;
	}
	return (-1);
}

int ft_brackets_is_valid(char *str, size_t len)
{
	size_t i;
	int ret;
	int i_closing;

	i = 0;
	while (i < len)
	{
		if ((ret = which_bracket(str[i])) != -1)
		{
			if (ret % 2 == 1)
				return (0);
			else
			{
				i_closing = ft_find_closing(str + i, brackets[ret + 1], len - i);
				if (i_closing == -1)
					return (0);
				else
				{
					str[i] = ' ';
					str[i_closing + i] = ' ';
					if (ft_brackets_is_valid(str + i + 1, i_closing) == 0)
						return (0);
				}
			}
		}
		i++;
	}
	return (1);
}

int ft_str_brackets_is_valid(const char *str, size_t len)
{
	char *tmp;
	int result;

	tmp = (char *)ft_memalloc((len + 1) * sizeof(char));
	if (tmp == NULL)
		return (-1);
	tmp = ft_strncpy(tmp, str, len);
	result = ft_brackets_is_valid(tmp, len); 
	ft_memdel((void **)&tmp);
	return (result);
}