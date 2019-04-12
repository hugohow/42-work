/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_current_precision.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:12:18 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 17:12:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_current_precision(char *str, t_flag *flag, int sign)
{
    int count;
    int i;

    i = 0;
    count = 0;
    if (flag->hash == 1 && sign != 0)
    {
        while (str[i])
        {
            if (str[i] == '0')
            {
                i++;
                if (flag->conv == 'o')
                {
                    count++;
                    while (str[i] && str[i] != ' ')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag->conv == 'x')
                {
                    i++;
                    while (str[i] && str[i] != ' ')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
                else if (flag->conv == 'X')
                {
                    i++;
                    while (str[i] && str[i] != ' ')
                    {
                        count++;
                        i++;
                    }
                    break;
                }
            }
            i++;
        }
        return (count);
    }
    else
    {
        while (str[i])
        {
            if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
            {
                while (str[i] && (ft_isdigit(str[i]) || ft_isalpha(str[i])))
                {
                    count++;
                    i++;
                }
                if (str[i] == '\0')
                    break;
            }
            i++;
        }
        return (count);
    }
    return (count);
}