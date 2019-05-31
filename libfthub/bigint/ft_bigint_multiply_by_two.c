/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_multiply_by_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:01:30 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/31 16:23:22 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid_digit(char c)
{
	if (ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}

char		*ft_bigint_multiply_by_two(char *output)
{
	int len;
	int ret;
	int dec;

	len = 0;
	while (output[len])
		len++;
	ret = 0;
	output[len + 1] = 0;
	while (len != 0 && is_valid_digit(output[len - 1]))
	{
		if (output[len - 1] == '.')
			output[len] = '.';
		else
		{
			dec = output[len - 1] - '0';
			output[len] = ((dec) * 2 + ret) % 10 + '0';
			ret = (dec) * 2 + ret < 10 ? 0 : 1;
		}
		len--;
	}
	output[len] = ret + '0';
	return (ft_bigint_trim(output));
}