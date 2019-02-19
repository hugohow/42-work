#include "ft_exit.h"


int is_exit(char *cmd)
{
    int i;

    i = 0;
    while (cmd[i] && cmd[i] == ' ')
        i++;
    if (cmd[i] == 'e')
    {
        if (ft_strcmp(cmd + i, "exit") == 0 || ft_strcmp(cmd + i, "exit ") >= 0)
            return (1);
        else
            return (0);
    }
    return (0);
}


void ft_exit(char *cmd, int success, struct termios *p_orig_termios)
{
    char **cmd_list;
    int i;

    cmd_list = ft_strsplit(cmd, ' ');
    if (cmd_list[1])
    {
        if (cmd_list[2])
        {
            ft_putstr_fd("Too many arguments Argument list too long", 2);
            return ;
        }
        i = 0;
        while (cmd_list[1][i] && cmd_list[1][i] == ' ')
            i++;
        while (cmd_list[1][i])
        {
            if (ft_isdigit(cmd_list[1][i]) == 0)
            {
                ft_putstr_fd("Numeric argument required", 2);
                ft_exit_terminal(p_orig_termios);
                exit(-1);
            }
            i++;
        }
        ft_exit_terminal(p_orig_termios);
        exit(ft_atoi(cmd_list[1]));
    }   
    ft_exit_terminal(p_orig_termios);
    exit(success);
}