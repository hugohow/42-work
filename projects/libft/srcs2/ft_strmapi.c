/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:12:30 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:12:31 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char *ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
    char        *new_str;
    unsigned int i;

    if (str == NULL)
		return (NULL);
    new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
    if (new_str == NULL)
        return (NULL);
    i = 0;
    while (str[i])
    {
        new_str[i] = (*f)(i, str[i]);
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}