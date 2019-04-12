/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_padding_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:49:41 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 18:49:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char *ft_apply_padding_p(char *str, t_flag *flag, int sign)
{
    char *to_add;
    unsigned int str_len;
    unsigned int i;
    int has_offset_zero;

    str_len = ft_strlen(str);
    if (flag->plus == 1 && sign >= 0)
        str_len++;
    if (sign < 0)
        str_len++;
    if (flag->plus == 0 && flag->space == 1 && sign >= 0)
        str_len++;
    has_offset_zero = flag->zero;
    // printf("flag->width : %d\n", flag->width);
    // printf("str_len : %d\n", str_len);
    to_add = malloc((flag->width + 2) * sizeof(char));
    i = 0;
    if (flag->width > str_len)
    {
        while (i < flag->width - str_len)
        {
            if (has_offset_zero == 1 && flag->minus == 0)
                to_add[i++] = '0';
            else
                to_add[i++] = ' ';
        }
        if (has_offset_zero == 1 && flag->minus == 0)
        {
            to_add[i++] = '0';
            to_add[i++] = '0';
            to_add[1] = 'x';
        }
    }
    to_add[i] = '\0';
    // printf("to_add : %s\n", to_add);

    // si l'espace doit être collé -> if (has_offset_zero == 1 && flag->minus == 0)
    if (has_offset_zero == 1 && flag->minus == 0)
    {
        if (flag->width > str_len)
        {
            str = ft_strjoin(to_add, str + 2);
        }
        if (flag->plus == 1 && sign >= 0)
            str = ft_strjoin("+", str);
        if (sign < 0)
            str = ft_strjoin("-", str);
        if (flag->plus == 0 && flag->space == 1 && sign >= 0)
            str = ft_strjoin(" ", str);
        return (str);
    }

    // les autres cas l'espace ne doit pas être collé, du coup on join le sign pouis le add
    if (flag->plus == 1 && sign >= 0)
        str = ft_strjoin("+", str);
    if (sign < 0)
        str = ft_strjoin("-", str);
    if (flag->plus == 0 && flag->space == 1 && sign >= 0)
        str = ft_strjoin(" ", str);
    if (flag->minus == 1)
        str = ft_strjoin(str, to_add);
    else
        str = ft_strjoin(to_add, str);
    return (str);
}

char *ft_apply_precision_p(char *str, int precision)
{
    unsigned int i;
    unsigned int k;
    unsigned int str_len;
    char *output;

    str_len = ft_strlen(str);
    if (precision < 0)
        return (str);
    if (str_len >= (unsigned int)precision)
    {
        return (ft_strjoin("0x", str));
    }
    output = malloc((precision + 4) * sizeof(char));
    i = 0;
    while (i < precision - str_len + 2)
    {
        output[i] = (i == 1) ? 'x' : '0';
        i++;
    }
    k = 0;
    while (k < str_len)
    {
        output[i] = str[k];
        i++;
        k++;
    }
    output[i] = '\0';
    // printf("apply precision : %s\n", output);
    return (output);
}