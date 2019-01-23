#include <string.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;

    i = 0;
    while (*(unsigned char *)(s + i) && i < n)
    {
        if (*(unsigned char *)(s + i) == (unsigned char)c)
            return ((void *)(s + i));
        i++;
    }
    if (c == '\0' && *(unsigned char *)(s + i) == '\0')
        return ((void *)(s + i));
    return (NULL);
}