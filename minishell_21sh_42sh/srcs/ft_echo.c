#include "ft_echo.h"



int ft_echo(int argc, char **argv, char ***p_environ, int fd0, int fd1, int fd2)
{
    int i;
    int flag_n;

    if (argc <= 1)
        return (0);
    if (p_environ)
    {

    }
    i = 0;
    flag_n = 0;
    argv++;
    if (argv[0] && ft_strcmp(argv[0], "-n") == 0)
    {
        flag_n = 1;
        i++;
    }
    if (fd0 && fd2)
    {
        
    }
    while (argv[i])
    {
        ft_putstr_fd(argv[i], fd1);
        ft_putstr_fd(" ", fd1);
        i++;
    }
    if (flag_n)
    {

    }
    else
    {
        
    }
    ft_putstr_fd("\n", fd1);
    return (0);
}