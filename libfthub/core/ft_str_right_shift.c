/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_right_shift.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:30:29 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/23 20:35:28 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** >> "abc" = " ab"
*/

char	*ft_str_right_shift(char *str, int len)
{
	int j;

	j = len;
	while (j > 0)
	{
		str[j] = str[j - 1];
		j--;
	}
	str[0] = ' ';
	return (str);
}