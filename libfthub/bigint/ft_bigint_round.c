/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_round.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:55:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 13:44:05 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_to_add(int n)
{
	int		i;
	char	*to_add;

	if (!(to_add = (char *)ft_memalloc((n + 4) * sizeof(char))))
		return (NULL);
	to_add = ft_strcpy(to_add, "0.1");
	i = 2;
	while (n != 0)
	{
		to_add[i] = '0';
		i++;
		n--;
	}
	to_add[i] = '1';
	i++;
	to_add[i] = 0;
	return (to_add);
}

static char	*ft_banker_round(char *dst, int precision, size_t limit, int i)
{
	int		j;
	char	*to_add;

	if (i < (int)limit)
	{
		j = i - 1;
		if (dst[i - 1] == '.')
		{
			i--;
			j--;
		}
		if ((dst[j] - '0') % 2 == 0)
		{
			dst[i] = 0;
			return (dst);
		}
		else
		{
			to_add = get_to_add(precision);
			dst = ft_bigint_add(dst, to_add, limit);
			ft_memdel((void **)&to_add);
			return (ft_bigint_round(dst, precision, limit));
		}
	}
	return (NULL);
}

static char	*ft_big_int_round_inf(char *dst, int precision, size_t limit, int i)
{
	(void)precision;
	if (i < (int)limit)
	{
		if (dst[i - 1] == '.')
			i--;
		dst[i] = 0;
		return (dst);
	}
	return (NULL);
}

static char	*ft_big_int_round_add(char *dst, int precision, size_t limit, int i)
{
	while (precision != 0 && i < (int)limit)
	{
		dst[i] = '0';
		i++;
		precision--;
	}
	if (dst[i - 1] == '.')
		i--;
	dst[i] = '\0';
	return (dst);
}

char		*ft_bigint_round(char *dst, int precision, size_t limit)
{
	int		i;
	char	*to_add;
	int		precision_cpy;

	if (precision < 0 || dst == NULL)
		return (dst);
	precision_cpy = precision;
	i = ft_bigint_get_index(dst, '.');
	if (dst[i] == 0)
		dst[i] = '.';
	while (dst[++i] && precision != 0)
		precision--;
	if (dst[i] == 0)
		return (ft_big_int_round_add(dst, precision, limit, i));
	else if (dst[i] == '5' && dst[i + 1] == 0)
		return (ft_banker_round(dst, precision_cpy, limit, i));
	else if (dst[i] < '5')
		return (ft_big_int_round_inf(dst, precision_cpy, limit, i));
	to_add = get_to_add(precision_cpy);
	dst = ft_bigint_add(dst, to_add, limit);
	ft_memdel((void **)&to_add);
	return (ft_bigint_round(dst, precision_cpy, limit));
}
