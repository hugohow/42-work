/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:55:17 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 22:55:57 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strdup(char *src)
{
	int	len;
	char	*output;

	while (str[len])
		len++;
	output = (char*)(malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	len = 0;
	while (str[len])
	{
		output[len] = src[len];
		len++;
	}
	output[len] = '\0';
	return (output);
}
