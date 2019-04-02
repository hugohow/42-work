#include <string.h>

size_t  ft_strlen(const char *str);

char    *ft_strncat(char *s1, const char *s2, size_t n)
{
    size_t i;
    size_t len1;

    len1 = ft_strlen(s1);
    i = 0;
    while(s2[i] && i < n)
    {
        s1[len1 + i] = s2[i];
        i++;
    }
    s1[len1 + i] = '\0';
    return (s1);
}
