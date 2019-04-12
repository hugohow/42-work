#include "ft_printf.h"

wchar_t *ft_apply_padding_w(wchar_t *str, t_flag *flag)
{
    wchar_t *to_add;
    unsigned int str_len;
    unsigned int i;

    str_len = ft_wcslen(str);
    if (flag->width > str_len)
    {
        to_add = (wchar_t *)malloc((flag->width + 1) * sizeof(wchar_t));
        i = 0;
        while (i < flag->width - str_len)
            to_add[i++] = ' ';
        to_add[i] = '\0';
        if (flag->minus == 1)
            return (ft_wstrjoin(str, to_add));
        else
            return (ft_wstrjoin(to_add, str));
    }

    return (str);
}