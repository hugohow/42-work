/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaglen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:39:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 19:40:49 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int is_valid_par(char c)
{
    if (c == ' ' || c == '#' || c == '0' || c == '-' || c == '+' || c == '*' || c == '$' || c == '.')
        return (1);
    if (ft_isdigit(c) == 1)
        return (1);
    if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L' || c == 't')
        return (1);
    return (0);
}

size_t ft_flaglen(const char *str)
{
    size_t  i;
    i = 1;
    // à voir après pour les cas moins basiques type ll, ...
    while (str[i] && is_valid_par(str[i]) == 1)
    {
        if (str[i] == '%')
            break;
        i++;
    }
    return (i);
}
