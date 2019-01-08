#include "ft_ls.h"

int main(int argc, char **argv)
{
    t_flag *flag;
    int i;

    i = 1;
    flag = NULL;
    // on essaye, si NULL c'est que argv 1 est autre chose
    if (argc >= 2)
        flag = ft_get_flag_info(argv[1]);
    if (flag != NULL)
        i++;
    else
        flag = ft_get_flag_info("");
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