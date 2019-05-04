/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:02:01 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/03 17:36:20 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *ft_bigint_trim_right(char *str)
{
	size_t i;
	size_t len;

	len = ft_strlen(str);
	i = len - 1;
	while (str[i] && str[i] == '0')
	{
		str[i] = 0;
		i--;
	}
	return (str);
}

static char *ft_bigint_trim_left(char *str)
{
	size_t nb;
	size_t i;
	size_t len;

	nb = 0;
	len = ft_strlen(str);
	while (str[nb] && str[nb] == '0')
		nb++;
	if (nb == 0)
		return (str);
	i = 0;
	while (str[i] && i + nb <= len)
	{
		str[i] = str[i + nb];
		i++;
	}
	while (i != len)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

char *ft_bigint_trim(char *str)
{
	str = ft_bigint_trim_left(str);
	str = ft_bigint_trim_right(str);
	return (str);
}
