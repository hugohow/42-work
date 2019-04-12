/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:16:11 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 17:16:17 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_delete_element(char *str, t_flag *flag, int i)
{
    int j;

    if (flag->minus == 1)
    {
        // on décale vers la gauche
        j = i + 1;
        while (str[j])
        {
            str[j - 1] = str[j];
            j++;
        }
        str[j] = ' ';
    }
    else
    {
        j = i;
        while (j > 0)
        {
            str[j] = str[j - 1];
            j--;
        }
        str[0] = ' ';
        // on décale vers la droite
    }
    return (str);
}