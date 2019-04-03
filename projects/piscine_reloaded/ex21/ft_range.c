/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:05:28 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/03 10:58:06 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *output;
	int i;
	int k;

	if (max <= min)
		return (NULL);
	output = (int *)malloc((max - min + 1) * sizeof(int));
	i = min;
	k = 0;
	while (i < max)
	{
		output[k] = i;
		k++;
		i++;
	}
	output[k] = 0;
	return (output);
}
