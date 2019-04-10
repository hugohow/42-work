/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:04:59 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/10 20:37:00 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nblen(long nb)
{
	size_t	nblen;

	nblen = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		nblen++;
	}
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	return (nblen);
}

char			*ft_itoa(int nb)
{
	char	*output;
	size_t	nb_len;
	long	n;

	n = nb;
	nb_len = ft_nblen(n);
	output = (char *)malloc((nb_len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[0] = n < 0 ? '-' : '0';
	n = n < 0 ? -n : n;
	output[nb_len] = '\0';
	while (n != 0)
	{
		output[--nb_len] = (n % 10) + '0';
		n /= 10;
	}
	return (output);
}
