#include <string.h>

size_t  ft_strlen(const char *str);

char *ft_strchr(const char *s, int c)
{
    size_t i;

    if ((char)c == '\0')
        return (char *)(s + ft_strlen(s));
    i = 0;
    while (*(s + i))
    {
        if (*(s + i) == (char)c)
            return (char *)(s + i);
        i++;
    }
    return (NULL);
}