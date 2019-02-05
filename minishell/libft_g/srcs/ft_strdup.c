#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dst, const char *src);

char    *ft_strdup(const char *s1)
{
    char *copy;

    copy = (char *)malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
    if (copy == NULL)
        return (NULL);
    copy = ft_strcpy(copy, s1);
    return (copy);
}
