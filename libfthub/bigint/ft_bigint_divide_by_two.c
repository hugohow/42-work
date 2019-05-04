/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_divide_by_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:01:01 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/04 15:08:45 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_bigint_divide_by_two(char *output, size_t limit)
{
	size_t i;
	size_t j;
	int finished;
	int even;

	output = ft_bigint_shift_right(output, 1, limit);
	output[0] = '0';
	i = 0;
	finished = 0;
	while (output[i] && finished != 1)
	{
		even = (output[i] - '0') % 2;
		while (output[i] && ft_isdigit(output[i]) == 0)
		{
			output[i - 1] = output[i];
			i++;
		}
		j = i + 1;
		while (output[j] && ft_isdigit(output[j]) == 0)
		{
			output[j - 1] = output[j];
			j++;
			i++;
		}
		if (output[j] == 0)
		{
			output[j] = '0';
			output[j + 1] = 0;
			finished = 1;
		}
		if (even == 0)
		{
			if (output[j] == '0' || output[j] == '1')
				output[i] = '0';
			if (output[j] == '2' || output[j] == '3')
				output[i] = '1';
			if (output[j] == '4' || output[j] == '5')
				output[i] = '2';
			if (output[j] == '6' || output[j] == '7')
				output[i] = '3';
			if (output[j] == '8' || output[j] == '9')
				output[i] = '4';
		}
		else
		{
			if (output[j] == '0' || output[j] == '1')
				output[i] = '5';
			if (output[j] == '2' || output[j] == '3')
				output[i] = '6';
			if (output[j] == '4' || output[j] == '5')
				output[i] = '7';
			if (output[j] == '6' || output[j] == '7')
				output[i] = '8';
			if (output[j] == '8' || output[j] == '9')
				output[i] = '9';
		}
		i = j;
	}
	return (ft_bigint_trim(output));
}