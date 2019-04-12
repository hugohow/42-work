/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:17:28 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 17:17:38 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_add_element(char *str, t_flag *flag, int i)
{
    if (flag->minus == 1 && flag->conv == ' ')
    {
        int j;
        j = ft_strlen(str) - 1;
        while (j > i)
        {
            str[j] = str[j - 1];
            j--;
        }
        str[i] = '0';
        return (str);
    }
    else if (flag->minus == 0 && str[0] == ' ')
    {
        int j;
        j = 0;
        while (j < i - 1)
        {
            str[j] = str[j + 1];
            j++;
        }
        str[j] = '0';
        return (str); 
    }
    else
    {
        char *tmp;
        int j;
        j = 0;
        tmp = malloc((i + 2) * sizeof(char));
        while (j < i)
        {
            tmp[j] = str[j];
            j++;
        }
        tmp[j] = '0';
        j++;
        tmp[j] = '\0';
        return (ft_strjoin(tmp, str + i));
    }
}