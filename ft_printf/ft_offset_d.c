#include "ft_printf.h"

char *offset_d(char *str, char *flag, int sign, char conv_char)
{
    char *to_add;
    unsigned int str_len;
    unsigned int i;
    unsigned int width;
    int has_offset_zero;

    str_len = ft_strlen(str);
    if (get_plus(flag) == 1 && sign >= 0)
        str_len++;
    if (sign < 0)
        str_len++;
    if (get_plus(flag) == 0 && get_space(flag) == 1 && sign >= 0)
        str_len++;
    width = get_width(flag);
    has_offset_zero = get_zero(flag);
    // printf("width : %d\n", width);
    // printf("str_len : %d\n", str_len);
    to_add = malloc((width + 2) * sizeof(char));
    i = 0;
    if (width > str_len)
    {
        while (i < width - str_len)
        {
            if (has_offset_zero == 1 && get_minus(flag) == 0 && get_precision(flag) == 0)
                to_add[i++] = '0';
            else
                to_add[i++] = ' ';
        }
    }
    if (!(has_offset_zero == 1 && get_minus(flag) == 0 && get_precision(flag) == 0) && get_hash(flag))
    {
        if (i != 0)
            to_add[i - 1] = '0';
        else
            str = ft_strjoin("0", str);
    }
    to_add[i] = '\0';
    // printf("to_add : %s\n", to_add);

    // si l'espace doit être collé -> if (has_offset_zero == 1 && get_minus(flag) == 0)
    if (has_offset_zero == 1 && get_minus(flag) == 0 && get_precision(flag) == 0)
    {
        str = ft_strjoin(to_add, str);
        if (get_plus(flag) == 1 && sign >= 0)
            str = ft_strjoin("+", str);
        if (sign < 0)
            str = ft_strjoin("-", str);
        if (get_plus(flag) == 0 && get_space(flag) == 1 && sign >= 0)
            str = ft_strjoin(" ", str);
        return (str);
    }

    // les autres cas l'espace ne doit pas être collé, du coup on join le sign pouis le add
    if (get_plus(flag) == 1 && sign >= 0)
        str = ft_strjoin("+", str);
    if (sign < 0)
        str = ft_strjoin("-", str);
    if (get_plus(flag) == 0 && get_space(flag) == 1 && sign >= 0)
        str = ft_strjoin(" ", str);
    if (get_minus(flag) == 1)
        str = ft_strjoin(str, to_add);
    else
        str = ft_strjoin(to_add, str);
    return (str);
}