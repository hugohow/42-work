#include "ft_ls.h"

int is_valid_flag(char c)
{
    if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
        return (1);
    return (0);
}

t_flag *ft_get_flag_info(char *argv, t_flag *flag)
{
    t_flag *new_flag;
    int i;

    new_flag = malloc(sizeof(t_flag));
    if (new_flag == NULL)
        return (NULL);
    if (flag == NULL)
    {
        new_flag->flag = argv;
        new_flag->has_l = 0;
        new_flag->has_cap_r = 0;
        new_flag->has_a = 0;
        new_flag->has_r = 0;
        new_flag->has_t = 0;
    }
    else
    {
        *new_flag = *flag;
    }

    i = 0;
    if (argv[i] == '\0')
        return (new_flag);
    if (argv[i] && argv[i] != '-')
    {
        return (NULL);
    }
    i++;
    while (argv[i])
    {
        if (is_valid_flag(argv[i]) == 0)
        {
            return (new_flag);
        }
        if (argv[i] == 'l')
            new_flag->has_l = 1;
        if (argv[i] == 'R')
            new_flag->has_cap_r = 1;
        if (argv[i] == 'a')
            new_flag->has_a = 1;
        if (argv[i] == 'r')
            new_flag->has_r = 1;
        if (argv[i] == 't')
            new_flag->has_t = 1;
        i++;
    }
    return (new_flag);
}