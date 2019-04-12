/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_get_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:30:05 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 15:30:12 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_flag_get_precision(char *flag)
{
    unsigned int i;
    int precision;

    i = 0;
    precision = 0;
    while (flag[i])
    {
        if (flag[i] == '.' && flag[i+1] && ft_isdigit(flag[i+1]))
        {
            i++;
            while (flag[i] && ft_isdigit(flag[i]))
            {
                precision = precision * 10 + (flag[i] - '0');
                i++;
            }
            return (precision);
        }
        else if (flag[i] == '.')
        {
            return (0);
        }
        i++;
    }
    return (-1);
}