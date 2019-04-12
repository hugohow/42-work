/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:14:06 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 17:20:19 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *add_one_zero(char *str, t_flag *flag, int sign)
{
    // char *output;
    int i;

    i = 0;
    if (flag->hash == 1 && sign != 0)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag->conv == 'o')
                {
                    return (ft_add_element(str, flag, i));
                }
                else if (flag->conv == 'x')
                {
                    i++;
                    return (ft_add_element(str, flag, i));
                }
                else if (flag->conv == 'X')
                {
                    i++;
                    return (ft_add_element(str, flag, i));
                }
            }
            i++;
        }
    }
    else
    {
        while (str[i])
        {
            if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
            {
                return (ft_add_element(str, flag, i));
            }
            i++;
        }
        // tu recherches le premier 0

    }
    return (str);
}

char *ft_add_zeros(char *str, t_flag *flag, int sign)
{
    // printf("\npour : %s, la preicision est de  : %d\n", str, ft_count_current_precision(str, flag, sign));
    // printf("\npour : %s, la precision voulue est de  : %d\n", str, flag->precision);

    // la precision voulue est bien
    if (ft_count_current_precision(str, flag, sign) == flag->precision)
        return (str);
    
    // il faut ajouter du gras
    str = add_one_zero(str, flag, sign);
    return (ft_add_zeros(str, flag, sign));
}