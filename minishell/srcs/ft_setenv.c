#include "ft_setenv.h"


int ft_setenv(int argc, char **argv)
{
    char **new_environ;
    char *env_line;
    int i;

    new_environ = NULL;
    if (argc > 3)
    {
        ft_putstr("setenv: Too many arguments.\n");
        return (0);
    }
    if (argc == 1)
        return (0);
    env_line = ft_strjoin(argv[1], "=");
    if (argc == 2)
        env_line = ft_strjoin(env_line, "");
    else
        env_line = ft_strjoin(env_line, argv[2]);
    if (change_line_env(argv[1], env_line) == 0)
    {
        new_environ = (char **)malloc((list_size(environ) + 2) * sizeof(char *));
        i = 0;
        while (i < list_size(environ))
        {
            new_environ[i] = environ[i];
            i++;
        }
        new_environ[i++] = env_line;
        new_environ[i] = 0;
        *(&environ) = new_environ;
    }

    return (0);
}