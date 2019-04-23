/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:18:46 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/23 16:22:47 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static size_t size_to_malloc(long long nb, size_t base_len)
{
	size_t size;
	long long nb_tmp;

	size = 0;
	nb_tmp = nb;
	while (nb_tmp != 0)
	{
		nb_tmp /= base_len;
		size++;
	}
	return (size);
}

char	*ft_convert_base(char *decimal, char *base)
{
	char		*output;
	long long	result;
	size_t		i;
	size_t		base_len;
	size_t		len;

	i = -1;
	result = 0;
	base_len = ft_strlen(base);
	while (decimal[++i])
		result = result * 10 + (decimal[i] - '0');
	len = size_to_malloc(result, base_len);
	output = (char *)malloc((len + 2) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[len--] = '\0';
	if (result == 0)
		output[0] = base[0];
	while (result != 0)
	{
		output[len--] = base[result % base_len];
		result /= base_len;
	}
	return (output);
}
