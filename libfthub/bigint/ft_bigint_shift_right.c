/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_shift_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:53:34 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/31 16:22:54 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bigint_shift_right(char *str, size_t nb, size_t limit)
{
	size_t len;

	len = ft_strlen(str);
	if (len == 0 || nb <= 0)
		return (str);
	len = len + nb;
	if (len + 1 > limit)
		return (NULL);
	str[len + 1] = 0;
	while (len >= nb)
	{
		str[len] = str[len - nb];
		len--;
	}
	while (nb != 0)
	{
		str[nb - 1] = '0';
		nb--;
	}
	return (str);
}