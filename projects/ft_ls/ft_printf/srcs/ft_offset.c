#include "ft_printf.h"

char *offset(char *str, char *flag)
{
    char *to_add;
    unsigned int str_len;
    unsigned int i;
    unsigned int width;

    str_len = ft_strlen(str);
    width = get_width(flag);
    if (width > str_len)
    {
        to_add = malloc((width + 1) * sizeof(char));
        i = 0;
        while (i < width - str_len)
            to_add[i++] = ' ';
        to_add[i] = '\0';
        if (get_minus(flag) == 1)
            return (ft_strjoin(str, to_add));
        else
            return (ft_strjoin(to_add, str));
    }

    return (str);
}