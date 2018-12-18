#include <string.h>
#include <wchar.h>

size_t  ft_wcslen(const wchar_t *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}