/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:20:34 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 14:47:24 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char* format, ...)
{
    va_list ap;
    size_t  n;
    size_t  i;
    size_t  format_len;
    size_t  *len;
    char    *flag;

    format_len = ft_strlen(format);
    flag = malloc((format_len + 2) * sizeof(char));
    n = count_var(format);
    va_start(ap, format);
    i = 0;
    len = malloc(sizeof(size_t));
    *len = 0;
    // format = ft_strchr(format, '%');
    // printf("All string : %s\n\n--------------------------\n\n", format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            bzero((void *)flag, format_len + 1);
            flag = ft_strncpy(flag, format + i, (int)count_par(format + i) + 1);
            ft_print_arg(&ap, flag, len);
            i += (int)count_par(format + i);
        }
        else
        {
            ft_putchar(format[i]);
            *len += 1;
        }
        i++;
    }
    va_end(ap);
    return (*len);
}