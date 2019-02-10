#include <string.h>

size_t  ft_strlen(const char *str);

char *ft_strrchr(const char *s, int c)
{
    size_t i;

    if ((char)c == '\0')
        return (char *)(s + ft_strlen(s));
    if (ft_strlen(s) == 0) 
        return (NULL);    
    i = ft_strlen(s) - 1;
    while (i > 0)
    {
        if (*(s + i) == (char)c)
            return (char *)(s + i);
        i--;
    }
    if (*s == (char)c)
        return (char *)s;
    return (NULL);
}