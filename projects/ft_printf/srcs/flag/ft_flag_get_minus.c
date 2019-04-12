/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_get_minus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:37:28 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 15:37:35 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_flag_get_minus(char *flag)
{
    unsigned int i;

    i = 0;
    while (flag[i] && ft_isdigit(flag[i]) == 0)
    {
        if (flag[i] == '-')
            return (1);
        i++;
    }
    return (0);
}