#include "ft_unsetenv.h"


int ft_unsetenv(int argc, char **argv, char ***p_environ)
{
    int i;

    if (argc == 1)
    {
        ft_putstr("unsetenv: Too few arguments.\n");
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        delete_line_env(argv[i], p_environ);
        i++;
    }    

    return (0);
}