#include "ft_echo.h"



int ft_echo(int argc, char **argv)
{
    int i;
    int flag_n;

    if (argc <= 1)
        return (0);
    i = 0;
    flag_n = 0;
    argv++;
    if (argv[0] && ft_strcmp(argv[0], "-n") == 0)
    {
        flag_n = 1;
        i++;
    }
    while (argv[i])
    {
        ft_putstr(argv[i]);
        ft_putstr(" ");
        i++;
    }
    if (flag_n)
    {

    }
    else
    {
        
    }
    ft_putstr("\n");
    return (0);
}