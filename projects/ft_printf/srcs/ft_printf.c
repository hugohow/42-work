/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:20:34 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/14 19:29:47 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_ADDED 1

int ft_printf(const char* format, ...)
{
    va_list ap;
    size_t  n;
    size_t  i;
    size_t  format_len;
    size_t  len;
    char    *flag;

    format_len = ft_strlen(format);
    flag = (char *)malloc((format_len + MAX_ADDED + 1) * sizeof(char));
	if (flag == NULL)
		return (-1);
    n = ft_count_variable(format);
    va_start(ap, format);
    i = 0;
	len = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            bzero((void *)flag, format_len + MAX_ADDED + 1);
            flag = ft_strncpy(flag, format + i, (int)ft_flaglen(format + i) + 1);
            ft_print_arg(&ap, flag, &len);
            i += (int)ft_flaglen(format + i);
        }
        else
        {
            ft_putchar(format[i]);
            len += 1;
        }
        i++;
    }
    free(flag);
    flag = NULL;
    va_end(ap);
    return (len);
}