/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:32:39 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/04 14:00:00 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_escapable(char c)
{
	if (c == '\t' || c == '\v'|| c == '\f' || c == '\r'
		|| c == '\n' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long result;
	int i;
  	int sign;

	result = 0;
  	sign = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1] && is_digit(str[i + 1]))
		{
			sign = -1;
			i++;
		}
		if (is_digit(str[i]))
		{
			while (str[i] && is_digit(str[i]))
			{
				result = result * 10 + (str[i] - '0');
				i++;
			}
      		return ((int)result * sign);
		}
		if (is_escapable(str[i]) == 0)
			break;
		i++;
	}
	return ((int)result * sign);
}