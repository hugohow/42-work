/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:13:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:13:03 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char *ft_strtrim(char const *str)
{
    size_t start;
    size_t end;
    size_t str_len;

    if (str == NULL)
        return (NULL);
    start = 0;
    str_len = ft_strlen(str);
    if (str_len == 0)
        return ((char *)str);
    while (str[start] && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n'))
    {
        start++;
    }
    if (start == str_len)
        return ("");
    end = str_len - 1;
    while (str[end] && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
    {
        end--;
    }
    return (ft_strsub(str, start, end - start + 1));
}
