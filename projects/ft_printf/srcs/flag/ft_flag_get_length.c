/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_get_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:27:34 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 15:28:50 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int is_valid_conversion(char c)
{
    // if (c == '\0')
    //     return (0);
    // sSpdDioOuUxXcC
    if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
        || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
        || c == 'c' || c == 'C')
        return (1);
    return (0);
}

static int is_valid_length(char c)
{
    // if (c == '\0')
    //     return (0);
    // sSpdDioOuUxXcC
    if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L' || c == 't')
        return (1);
    return (0);
}

int ft_flag_get_length(char *flag)
{
    // invalid -> -1
    // no -> 0
    // hh -> 1
    // h -> 2
    // l -> 3
    // ll -> 4
    // j -> 5
    // z -> 6
    size_t i;

    i = 0;
    while (flag[i] && is_valid_conversion(flag[i]) == 0)
        i++;
    i--;
    if (i > 0)
    {
        while (i > 0 && is_valid_length(flag[i]) == 0)
        {
            i--;
        }
        if (flag[i] == 'j')
            return (5);
        if (flag[i] == 'z')
            return (6);
        if (flag[i] == 'h')
        {
            if (i > 1 && flag[i - 1] == 'h')
                return (1);
            return (2);
        }
        if (flag[i] == 'l')
        {
            if (i > 1 && flag[i - 1] == 'l')
                return (4);
            return (3);
        }
    }
    return (0);
}