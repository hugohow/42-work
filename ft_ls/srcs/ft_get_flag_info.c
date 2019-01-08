#include "ft_ls.h"

int is_valid_flag(char c)
{
    if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
        return (1);
    return (0);
}

t_flag *ft_get_flag_info(char *argv)
{
    t_flag *flag;
    int i;

    flag = malloc(sizeof(t_flag));
    if (flag == NULL)
        return (NULL);
    flag->flag = argv;
    flag->has_l = 0;
    flag->has_cap_r = 0;
    flag->has_a = 0;
    flag->has_r = 0;
    flag->has_t = 0;

    i = 0;
    if (argv[i] == '\0')
        return (flag);
    if (argv[i] && argv[i] != '-')
    {
        ft_printf("erreur");
        return (NULL);
    }
    i++;
    while (argv[i])
    {
        if (is_valid_flag(argv[i]) == 0)
        {
            ft_printf("erreur");
            return (flag);
        }
        if (argv[i] == 'l')
            flag->has_l = 1;
        if (argv[i] == 'R')
            flag->has_cap_r = 1;
        if (argv[i] == 'a')
            flag->has_a = 1;
        if (argv[i] == 'r')
            flag->has_r = 1;
        if (argv[i] == 't')
            flag->has_t = 1;
        i++;
    }
    return (flag);
}