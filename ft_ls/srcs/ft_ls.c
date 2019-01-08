#include "ft_ls.h"

int main(int argc, char **argv)
{
    t_flag *flag;
    int i;

    i = 1;
    // on essaye, si NULL c'est que argv 1 est autre chose
    if (argc >= 2)
        flag = ft_get_flag_info(argv[1]);
    else
        flag = ft_get_flag_info("");
    if (flag != NULL)
        i++;
    if (i >= argc)
    {
        ft_print_files(".", flag);
        return (0);
    }
    while (i < argc)
    {
        ft_print_files(argv[i], flag);
        i++;
    }
    return (0);
}