/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_left_shift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:29:25 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/23 20:35:01 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** "abc" << = "bc "
*/

char	*ft_str_left_shift(char *str, int len)
{
	int j;

	j = 0;
	while (j < len - 1)
	{
		str[j] = str[j + 1];
		j++;
	}
	str[j] = ' ';
	return (str);
}
