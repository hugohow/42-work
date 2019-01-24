#include "ft_unsetenv.h"


int ft_unsetenv(int argc, char **argv, char ***p_environ)
{
    if (argc == 1)
    {
        ft_putstr("unsetenv: Too few arguments.\n");
        return (0);
    }
    if (argc > 2)
        return (0);
    delete_line_env(argv[1], p_environ);

    return (0);
}