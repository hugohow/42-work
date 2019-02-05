#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);
char    *ft_strsub(char const *str, unsigned int start, size_t len);

char *ft_strtrim(char const *str)
{
    size_t start;
    size_t end;
    size_t str_len;

    if (str == NULL)
        return (NULL);
    start = 0;
    str_len = ft_strlen(str);
    if (str_len == 0)
        return ((char *)str);
    while (str[start] && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n'))
    {
        start++;
    }
    if (start == str_len)
        return ("");
    end = str_len - 1;
    while (str[end] && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
    {
        end--;
    }
    return (ft_strsub(str, start, end - start + 1));
}
