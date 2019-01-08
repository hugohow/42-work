#include "ft_ls.h"

int main(int argc, char **argv)
{
    t_flag *flag;

    if (argc == 3)
    {
        flag = ft_get_flag_info(argv[1]);
        ft_print_files(argv[2], flag);
        return (0);
    }
    if (argc == 2)
    {
        flag = ft_get_flag_info(argv[1]);
        ft_print_files(".", flag);
        return (0);
    }
    flag = ft_get_flag_info("");
    ft_print_files(".", flag);
    return (0);
}