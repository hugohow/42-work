/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:03:15 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/01 15:16:37 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int get_index(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && str[i] != c)
		i++;
	return (i);
}


static char *fill_right(char *str, size_t len)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
	return (str);
}

char *ft_bigint_add(char *dst, const char *to_add, size_t limit)
{
	int dot_index;
	int dst_index;
	int to_add_index;
	int len;
	char *to_add_cpy;
	int ret;
	int dec;
	
	len = ft_strlen(dst) < ft_strlen(to_add) ? ft_strlen(to_add) : ft_strlen(dst);
	to_add_cpy = (char *)malloc((len*2) * sizeof(char));
	to_add_cpy = ft_strcpy(to_add_cpy, to_add);
	dst_index = get_index(dst, '.');
	to_add_index = get_index(to_add_cpy, '.');
	dot_index = dst_index > to_add_index ? dst_index : to_add_index;
	dot_index++;
	dst = ft_bigint_shift_right(dst, dot_index - dst_index, limit);
	to_add_cpy = ft_bigint_shift_right(to_add_cpy, dot_index - to_add_index, limit);
	len = ft_strlen(dst) < ft_strlen(to_add_cpy) ? ft_strlen(to_add_cpy) : ft_strlen(dst);
	dst = fill_right(dst, len);
	to_add_cpy = fill_right(to_add_cpy, len);

	ret = 0;
	len--;
	while (len >= 0)
	{
		if (dst[len] == '.')
		{

		}
		else
		{
			dec = (to_add_cpy[len] - '0') + (dst[len] - '0');
			dst[len] = (dec+ ret) % 10 + '0';
			ret = (dec+ ret) < 10 ? 0 : 1;
		}
		len--;
	}
	free(to_add_cpy);
	// printf("dst  :\t\t%s\n", dst);
	return (ft_bigint_trim(dst));
}