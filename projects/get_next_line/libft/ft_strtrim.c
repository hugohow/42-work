/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:13:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/04 16:38:36 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	int start_index;
	int end_index;
	int len;
	int k;
	char *output;

	start_index = 0;
	if (str == NULL)
		return (NULL);
  end_index = strlen(str);
  end_index--;
	while (str[start_index] && (str[start_index] == ' ' || str[start_index] == '\t' || str[start_index] == '\n'))
		start_index++;
	while (end_index > 0 && (str[end_index] == ' ' || str[end_index] == '\t' || str[end_index] == '\n'))
		end_index--;
 
	len = end_index == -1 ? 2 : end_index - start_index + 2;
// 	printf("start_index of %d\n", start_index);
//   printf("end_index of %d\n", end_index);
// 	printf("malloc of %d + 0\n", len);
	output = (char *)(malloc(len * sizeof(char)));
	if (output == NULL)
		return (NULL);
	k = 0;
	while (start_index < end_index + 1)
	{
		output[k] = str[start_index];
		start_index++;
		k++;
	}
	if (end_index == -1)
		return ("");
	output[k] = 0;
	return (output);
}