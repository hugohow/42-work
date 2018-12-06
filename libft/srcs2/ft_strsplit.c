#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);

size_t   count_words(char const *str, char c)
{
    size_t i;
    size_t count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] != c)
        {
            while (str[i] && str[i] != c)
                i++;
            count++;
        }
        else
            i++;
    }
    return (count);
}

char    **ft_strsplit(char const *str, char c)
{
    char **list;
    char *word;
    size_t str_len;
    size_t i;
    size_t j;
    size_t k;

    if (str == NULL)
        return (NULL);
    list = (char **)malloc((count_words(str, c) + 1) * sizeof(char *));
    if (list == NULL)
        return (NULL);
    i = 0;
    k = 0;
    str_len = ft_strlen(str);
    while (str[i])
    {
        if (str[i] != c)
        {
            word = malloc((str_len + 1) * sizeof(char));
            j = 0;
            if (word == NULL)
                return (NULL);
            while (str[i] && str[i] != c)
                word[j++] = str[i++];
            word[j] = '\0';
            list[k++] = word;
        }
        else
            i++;
    }
    list[k++] = 0;
    return (list);
}
