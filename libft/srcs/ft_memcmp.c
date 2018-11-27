#include <string.h>

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;

    i = 0;
    while(i < n)
    {
        if (*(char *)(s1 + i) == '\0' && *(char *)(s2 + i) == '\0')
            return (0);
        if (*(char *)(s1 + i) == '\0' || *(char *)(s2 + i) == '\0')
            break;
        if (*(char *)(s1 + i) != *(char *)(s2 + i))
            break;
        i++;
    }
    if (i == n)
        return (0);
    return ((int)(*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i)));
}
