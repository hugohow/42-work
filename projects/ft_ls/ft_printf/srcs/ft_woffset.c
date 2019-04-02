#include "ft_printf.h"

wchar_t *woffset(wchar_t *str, char *flag)
{
    wchar_t *to_add;
    unsigned int str_len;
    unsigned int i;
    unsigned int width;

    str_len = ft_wcslen(str);
    width = get_width(flag);
    if (width > str_len)
    {
        to_add = (wchar_t *)malloc((width + 1) * sizeof(wchar_t));
        i = 0;
        while (i < width - str_len)
            to_add[i++] = ' ';
        to_add[i] = '\0';
        if (get_minus(flag) == 1)
            return (ft_wstrjoin(str, to_add));
        else
            return (ft_wstrjoin(to_add, str));
    }

    return (str);
}