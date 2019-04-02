/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugohow-choong <hugohow-choong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:05:28 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 13:38:23 by hugohow-cho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *output;
	int i;
	int k;

	if (max < min)
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
