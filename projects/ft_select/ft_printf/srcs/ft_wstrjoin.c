#include <wchar.h>
#include <string.h>
#include <stdlib.h>

size_t  ft_wcslen(const wchar_t *str);

wchar_t *ft_wstrjoin(wchar_t const *str1, wchar_t const *str2)
{
    wchar_t *new_str;
    size_t i;
    size_t j;

    if (str1 == NULL || str2 == NULL)
        return (NULL);
    new_str = (wchar_t *)malloc((ft_wcslen(str1) + ft_wcslen(str2) + 1) * sizeof(wchar_t));
    if (new_str == NULL)
        return (NULL);
    i = 0;
    while (str1[i] != L'\0')
    {
        new_str[i] = str1[i];
        i++;
    }
    j = 0;
    while (str2[j] != L'\0')
    {
        new_str[i] = str2[j++];
        i++;
    }    
    new_str[i] = L'\0';
    return (new_str);
}