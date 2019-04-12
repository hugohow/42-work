/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_zeros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:13:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 19:32:07 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char *delete_one_zero(char *str, t_flag *flag, int sign)
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
                    return (ft_delete_element(str, flag, i));
                }
                else if (flag->conv == 'x')
                {
                    i++;
                    return (ft_delete_element(str, flag, i));
                }
                else if (flag->conv == 'X')
                {
                    i++;
                    return (ft_delete_element(str, flag, i));
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
                return (ft_delete_element(str, flag, i));
            }
            i++;
        }
        // tu recherches le premier 0

    }
    return (str);
}

char *ft_delete_zeros(char *str, t_flag *flag, int sign)
{

    // printf("\npour : %s, on peut supprimer : %d\n", str, ft_count_zeros_possible_to_delete(str, flag, sign));
    // printf("\npour : %s, la preicision est de  : %d\n", str, ft_count_current_precision(str, flag, sign));
    // printf("\npour : %s, la precision voulue est de  : %d\n", str, flag->precision);

    // plus de 0 à delete
    if (ft_count_zeros_possible_to_delete(str, flag, sign) == 0)
        return (str);
    // la precision voulue est bien
    if (ft_count_current_precision(str, flag, sign) == flag->precision)
        return (str);
    
    // il faut enlever du gras
    
    str = delete_one_zero(str, flag, sign);
    return (ft_delete_zeros(str, flag, sign));
}
