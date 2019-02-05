#include <string.h>

int     ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while (*(s1 + i) && *(s2 + i) && *(s1 + i) == *(s2 + i))
    {
        i++;
    }
    if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
        return (0);
    return ((int)((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i)));
}
