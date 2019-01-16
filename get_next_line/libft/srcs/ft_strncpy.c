#include <string.h>

size_t  ft_strlen(const char *str);

char    *ft_strncpy(char *dst, const char *src, size_t len)
{
    size_t i;

    i = 0;
    while (src[i] && i < len)
    {
        dst[i] = src[i];
        i++;
    }
    if (i == len)
        return (dst);
    while (i < len)
    {
        dst[i] = 0;
        i++;
    }
    return (dst);
}