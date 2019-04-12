#include "ft_printf.h"


char *add_prefix(char *str, char conv)
{
    if (conv == 'o')
    {
        // if (!(str[0] && str[0] == '0'))
            str = ft_strjoin("0", str);
    }
    else if (conv == 'x')
    {
        // if (!(str[0] && str[0] == '0' && str[1] && str[1] == 'x'))
            str = ft_strjoin("0x", str);
    }
    else if (conv == 'X')
    {
        // if (!(str[0] && str[0] == '0' && str[1] && str[1] == 'X'))
        // {
            str = ft_strjoin("0X", str);
        // }
    }
    else
    {

    }
    return (str);
}


char *offset_d(char *str, t_flag *flag, int sign)
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
    if (flag->zero == 1)
        has_offset_zero = 1;
    else
        has_offset_zero = 0;
    if (flag->hash && sign != 0)
    {
            if (flag->conv == 'o')
            {
                if (!(str[0] && str[0] == '0'))
                    str_len += 1;
            }
            else if (flag->conv == 'x')
            {
                if (!(str[0] && str[0] == '0' && str[1] && str[1] == 'x'))
                {
                    str_len += 2;
                }
            }
            else if (flag->conv == 'X')
            {
                if (!(str[0] && str[0] == '0' && str[1] && str[1] == 'X'))
                    str_len += 2;
            }
            else
            {
                
            }
    }
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
    }
    to_add[i] = '\0';
    // printf("to_add : %s\n", to_add);
    // si l'espace doit être collé -> if (has_offset_zero == 1 && flag->minus == 0)
    if (has_offset_zero == 1 && flag->minus == 0)
    {
        str = ft_strjoin(to_add, str);
        if (flag->hash && sign != 0)
            str = add_prefix(str, flag->conv);
        if (flag->plus == 1 && sign >= 0)
            str = ft_strjoin("+", str);
        if (sign < 0)
            str = ft_strjoin("-", str);
        if (flag->plus == 0 && flag->space == 1 && sign >= 0)
            str = ft_strjoin(" ", str);
    }
    else
    {
        // les autres cas l'espace ne doit pas être collé, du coup on join le sign pouis le add
        if (flag->plus == 1 && sign >= 0)
            str = ft_strjoin("+", str);
        if (sign < 0)
            str = ft_strjoin("-", str);
        if (flag->plus == 0 && flag->space == 1 && sign >= 0)
            str = ft_strjoin(" ", str);
        if (flag->minus == 1)
        {
            if (flag->hash && sign != 0)
                str = add_prefix(str, flag->conv);
            str = ft_strjoin(str, to_add);
        }
        else
        {
            if (flag->hash && sign != 0)
                str = add_prefix(str, flag->conv);
            str = ft_strjoin(to_add, str);   
        }     
    }
    return (str);
}