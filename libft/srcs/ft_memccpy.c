#include <string.h>

void    *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        *(char*)(dst + i) = *(char*)(src + i);
        if (*(char*)(src + i) == (unsigned char)c)
            break;
        i++;
    }
    if (i == n)
        return (NULL);
    else
        return (dst + i + 1);
};
