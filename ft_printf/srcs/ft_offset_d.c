#include "ft_printf.h"


char *add_prefix(char *str, char conv_char)
{
    if (conv_char == 'o')
    {
        // if (!(str[0] && str[0] == '0'))
            str = ft_strjoin("0", str);
    }
    else if (conv_char == 'x')
    {
        // if (!(str[0] && str[0] == '0' && str[1] && str[1] == 'x'))
            str = ft_strjoin("0x", str);
    }
    else if (conv_char == 'X')
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


char *offset_d(char *str, char *flag, int sign, char conv_char)
{
    char *to_add;
    unsigned int str_len;
    unsigned int i;
    unsigned int width;
    int has_offset_zero;

    width = get_width(flag);
    str_len = ft_strlen(str);
    if (get_plus(flag) == 1 && sign >= 0)
        str_len++;
    if (sign < 0)
        str_len++;
    if (get_plus(flag) == 0 && get_space(flag) == 1 && sign >= 0)
        str_len++;
    if (get_zero(flag) == 1)
        has_offset_zero = 1;
    else
        has_offset_zero = 0;
    if (get_hash(flag) && sign != 0)
    {
            if (conv_char == 'o')
            {
                if (!(str[0] && str[0] == '0'))
                    str_len += 1;
            }
            else if (conv_char == 'x')
            {
                if (!(str[0] && str[0] == '0' && str[1] && str[1] == 'x'))
                {
                    str_len += 2;
                }
            }
            else if (conv_char == 'X')
            {
                if (!(str[0] && str[0] == '0' && str[1] && str[1] == 'X'))
                    str_len += 2;
            }
            else
            {
                
            }
    }
    to_add = malloc((width + 2) * sizeof(char));
    i = 0;
    if (width > str_len)
    {
        while (i < width - str_len)
        {
            if (has_offset_zero == 1 && get_minus(flag) == 0)
                to_add[i++] = '0';
            else
                to_add[i++] = ' ';
        }
    }
    to_add[i] = '\0';
    // printf("to_add : %s\n", to_add);
    // si l'espace doit être collé -> if (has_offset_zero == 1 && get_minus(flag) == 0)
    if (has_offset_zero == 1 && get_minus(flag) == 0)
    {
        str = ft_strjoin(to_add, str);
        if (get_hash(flag) && sign != 0)
            str = add_prefix(str, conv_char);
        if (get_plus(flag) == 1 && sign >= 0)
            str = ft_strjoin("+", str);
        if (sign < 0)
            str = ft_strjoin("-", str);
        if (get_plus(flag) == 0 && get_space(flag) == 1 && sign >= 0)
            str = ft_strjoin(" ", str);
    }
    else
    {
        // les autres cas l'espace ne doit pas être collé, du coup on join le sign pouis le add
        if (get_plus(flag) == 1 && sign >= 0)
            str = ft_strjoin("+", str);
        if (sign < 0)
            str = ft_strjoin("-", str);
        if (get_plus(flag) == 0 && get_space(flag) == 1 && sign >= 0)
            str = ft_strjoin(" ", str);
        if (get_minus(flag) == 1)
        {
            if (get_hash(flag) && sign != 0)
                str = add_prefix(str, conv_char);
            str = ft_strjoin(str, to_add);
        }
        else
        {
            if (get_hash(flag) && sign != 0)
                str = add_prefix(str, conv_char);
            str = ft_strjoin(to_add, str);   
        }     
    }
    return (str);
}