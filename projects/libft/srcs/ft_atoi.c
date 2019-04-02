/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:32:39 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:09:07 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LL_LIMIT 9223372036854775807

int	is_valid(char c)
{
	if (c == '\t' || c == '\v'|| c == '\f' || c == '\r'
		|| c == '\n' || c == ' ' || c == '+' || c == '-')
		return (1);
	if (ft_isdigit(c) == 1)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t i;
	int sign;
	long long result;

	i = -1;
	sign = str[0] == '-' ? -1 : 1;
	result = 0;
	while (str[++i] && is_valid(str[i]) == 1)
	{
		if (ft_isdigit(str[i]) == 1)
		{
			while (str[i] && is_digit(str[i]) == 1)
			{
				if (result <= (LL_LIMIT - (str[i] - '0')) / 10)
					result = result * 10 + (str[i++] - '0');
				else
					return (-1);
			}
		}
	}
	return (int)(sign * result);
}
