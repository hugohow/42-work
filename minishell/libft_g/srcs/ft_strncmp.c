#include <string.h>

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (*(s1 + i) && *(s2 + i) && *(s1 + i) == *(s2 + i) && i < n)
    {
        i++;
    }
    if (i == n)
        return (0);
    if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
        return (0);
    return ((int)((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i)));
}
