/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:03:15 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/01 15:23:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_index(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*fill_right(char *str, size_t len)
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

static char	*ft_get_to_add(char *dst, const char *add, size_t limit)
{
	char	*ad_cp;
	int		len;
	int		add_index;
	int		dot_index;
	int		dst_index;

	len = ft_strlen(dst) < ft_strlen(add) ? ft_strlen(add) : ft_strlen(dst);
	if (!(ad_cp = (char *)ft_memalloc((len * 2) * sizeof(char))))
		return (NULL);
	ad_cp = ft_strcpy(ad_cp, add);
	dst_index = get_index(dst, '.');
	add_index = get_index(ad_cp, '.');
	dot_index = dst_index > add_index ? dst_index : add_index;
	dot_index++;
	dst = ft_bigint_shift_right(dst, dot_index - dst_index, limit);
	ad_cp = ft_bigint_shift_right(ad_cp, dot_index - add_index, limit);
	len = ft_strlen(dst) < ft_strlen(ad_cp) ? ft_strlen(ad_cp) : ft_strlen(dst);
	dst = fill_right(dst, len);
	ad_cp = fill_right(ad_cp, len);
	return (ad_cp);
}

char		*ft_bigint_add(char *dst, const char *to_add, size_t limit)
{
	int		len;
	char	*add;
	int		ret;
	int		dec;

	add = ft_get_to_add(dst, to_add, limit);
	len = ft_strlen(dst) < ft_strlen(add) ? ft_strlen(add) : ft_strlen(dst);
	ret = 0;
	len--;
	while (len >= 0)
	{
		if (dst[len] != '.')
		{
			dec = (add[len] - '0') + (dst[len] - '0');
			dst[len] = (dec + ret) % 10 + '0';
			ret = (dec + ret) < 10 ? 0 : 1;
		}
		len--;
	}
	ft_memdel((void **)&add);
	return (ft_bigint_trim(dst));
}
