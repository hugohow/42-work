/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_get_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:39:10 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 15:39:20 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_flag_get_zero(char *str)
{
    unsigned int i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]))
        {
            if (str[i] == '0')
                return (1);
            break;
        }
        i++;        
    }
    return (0);
}