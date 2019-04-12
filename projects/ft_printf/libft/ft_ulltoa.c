/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:25:05 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 19:29:17 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nblen_ull(unsigned long long nb)
{
	size_t	nblen;

	nblen = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	return (nblen);
}

char			*ft_ulltoa(unsigned long long nb)
{
	char				*output;
	size_t				nb_len;

	nb_len = ft_nblen_ull(nb);
	output = (char *)malloc((nb_len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[0] = '0';
	output[nb_len] = '\0';
	while (nb != 0)
	{
		output[--nb_len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (output);
}
