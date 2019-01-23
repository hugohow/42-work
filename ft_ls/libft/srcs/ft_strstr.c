#include <string.h>

size_t  ft_strlen(const char *str);

char    *ft_strstr(const char *str, const char *to_find)
{
    size_t to_find_len;
    size_t i;
    size_t j;

    to_find_len = ft_strlen(to_find);
    if (to_find_len == 0)
        return (char *)(str);
    i = 0;
    while (str[i])
    {
        if (str[i] == to_find[0])
        {
            j = 0;
            while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
                j++;
            if (to_find[j] == '\0')
                return (char *)(str + i);
        }
        i++;
    }
    return (NULL);
}