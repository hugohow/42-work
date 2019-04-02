/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:12:13 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:12:15 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *str1, char const *str2)
{
    char *new_str;
    size_t i;
    size_t j;

    if (str1 == NULL || str2 == NULL)
        return (NULL);
    new_str = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
    if (new_str == NULL)
        return (NULL);
    i = 0;
    while (str1[i])
    {
        new_str[i] = str1[i];
        i++;
    }
    j = 0;
    while (str2[j])
    {
        new_str[i] = str2[j++];
        i++;
    }    
    new_str[i] = '\0';
    return (new_str);
}
