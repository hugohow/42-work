#include "get_line_env.h"

char *get_line_env(char *str)
{
    size_t i;
    size_t j;

    i = 0;
    while (environ[i])
    {

        if (environ[i][0] == str[0])
        {
            j = 0;
            while (str[j] && environ[i][j] && environ[i][j] == str[j])
            {
                j++;
            }
            if (j == ft_strlen(str))
                return (environ[i]);
        }
        i++;
    }
    return (NULL);
}

int change_line_env(char *key, char *line)
{
    size_t i;
    size_t j;

    i = 0;
    while (environ[i])
    {

        if (environ[i][0] == key[0])
        {
            j = 0;
            while (key[j] && environ[i][j] && environ[i][j] == key[j])
            {
                j++;
            }
            if (j == ft_strlen(key))
            {
                *(environ + i) = line;
                return (1);
            }
        }
        i++;
    }
    return (0);
}

int delete_line_env(char *key)
{
    size_t i;
    size_t j;
    size_t k;

    i = 0;
    while (environ[i])
    {

        if (environ[i][0] == key[0])
        {
            j = 0;
            while (key[j] && environ[i][j] && environ[i][j] == key[j])
            {
                j++;
            }
            if (j == ft_strlen(key))
            {
                k = i + 1;
                while (environ[k])
                {
                    environ[k - 1] = environ[k];
                    k++;
                }
                environ[k - 1] = environ[k];
                return (1);
            }
        }
        i++;
    }
    return (0);
}