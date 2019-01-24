#include "get_line_env.h"

char *get_line_env(char *str, char **environ)
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

int change_line_env(char *key, char *line, char ***p_environ)
{
    size_t i;
    size_t j;
    char **environ;

    environ = *p_environ;
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
                *p_environ = environ;
                return (1);
            }
        }
        i++;
    }
    return (0);
}

int delete_line_env(char *key, char ***p_environ)
{
    size_t i;
    size_t j;
    size_t k;
    char **environ;

    environ = *p_environ;
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
                *p_environ = environ;
                return (1);
            }
        }
        i++;
    }
    *p_environ = environ;
    return (0);
}