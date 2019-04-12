/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:11:14 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 18:47:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_apply_precision(char *str, t_flag *flag, int sign)
{
    unsigned int str_len;
    str_len = ft_strlen(str);


    if (sign == 0)
    {
        if (flag->width == 0 && flag->precision == 0)
        {
            // very special case
            if (flag->conv == 'o')
                return ("0");
            if (flag->plus)
                return ("+");
            if (flag->space)
                return (" ");
            return ("");
        }
        // on enleve un 0 (et il ne doit y avoir qu'un seul)
    }
    if (flag->precision < 0)
        return (str);

    // si flag->precision == 0

    // voir si l'element est 0 ou pas
    // si oui -> il faut 


    // si str_len == flag->precision
    if (str_len == (unsigned int)flag->precision)
        return (str);

    
    if (ft_count_current_precision(str, flag, sign) > flag->precision)
    {
        // alors on doit enlever du gras (du 0)
        return (ft_delete_zeros(str, flag, sign));
    }

    
    if (ft_count_current_precision(str, flag, sign) < flag->precision)
    {
        // alors on doit rajouter du gras
        return (ft_add_zeros(str, flag, sign));
        // return (str);
    }   

    return (str);
}