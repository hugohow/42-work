/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:44:43 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 18:46:48 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char *ft_apply_padding(char *str, t_flag *flag)
{
    char *to_add;
    unsigned int str_len;
    unsigned int i;

    str_len = ft_strlen(str);
    if (flag->width > str_len)
    {
        to_add = malloc((flag->width + 1) * sizeof(char));
        i = 0;
        while (i < flag->width - str_len)
            to_add[i++] = ' ';
        to_add[i] = '\0';
        if (flag->minus == 1)
            return (ft_strjoin(str, to_add));
        else
            return (ft_strjoin(to_add, str));
    }

    return (str);
}