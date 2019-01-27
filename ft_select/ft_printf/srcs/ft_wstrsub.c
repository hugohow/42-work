#include <wchar.h>
#include <string.h>
#include <stdlib.h>

size_t  ft_wcslen(const wchar_t *str);

wchar_t *ft_wstrsub(wchar_t const *str, unsigned int start, size_t len)
{
    wchar_t *new_str;
    size_t i;

    if (str == NULL)
        return (NULL);
    if (len + start > ft_wcslen(str))
        return (NULL);
    new_str = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));
    if (new_str == NULL)
        return (NULL);
    i = start;
    while (i - start != len)
    {
        new_str[i - start] = str[i];
        i++;
    }
    new_str[len] = L'\0';
    return (new_str);
}