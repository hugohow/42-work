/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:16:48 by hhow-cho          #+#    #+#             */
/*   Updated: 2018/11/06 20:45:14 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(char *str)
{
	unsigned int	i;
	long long		result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' ||
		str[i] == '\r' || str[i] == '\n' || str[i] == '+' || str[i] == ' ')
	{
		i++;
		if (str[i] == '+' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
	}
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] - '0') >= 0 && (str[i] - '0') <= 9)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
