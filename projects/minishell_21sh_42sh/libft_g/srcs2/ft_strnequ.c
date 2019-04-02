#include <string.h>

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
    size_t i;

    if (s1 == NULL || s2 == NULL)
        return (0);
    i = 0;
    while (*s1 && *s2 && *s1 == *s2 && i < n)
    {
        s1++;
        s2++;
        i++;
    }
    if (i == n)
        return (1);
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    return (0);
}