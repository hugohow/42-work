#include "ft_env.h"

void ft_print_env(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putstr(str[i]);
        ft_putchar('\n');
        i++;
    }
}

char **clear_environ(void)
{
    char **output;

    output = malloc(sizeof(char *));
    output[0] = 0;
    return (output);
}

int ft_env(int argc, char **argv, char ***p_environ)
{
    pid_t pid;
    int i;
    int j;
    char **copy_env;
    int has_v;
    // print env
    if (argc)
    {
        
    }
    // if (argc == 1)
    // {
        ft_print_env(*p_environ);
        return (0);
    // }

    // set environment and execute command, 
    pid = fork();
    if (pid == 0)
    {
        // child
        has_v = 0;
        copy_env = copy_environ(*p_environ);
        i = 0;



        while (argv[i])
        {
            if (argv[i][0] == '-')
            {
                j = 0;
                while (argv[i][j])
                {

                    j++;
                }
                // c'est un flag

            }


            if (ft_strcmp(argv[i], "-v") == 0)
            {
                i++;
            }
            if (ft_strcmp(argv[i], "-i") == 0)
            {
                if (has_v)
                    ft_printf("#env clearing environ\n");
                copy_env = clear_environ();
                i++;
            }
            if (ft_strcmp(argv[i], "-u") == 0)
            {
                if (argv[i + 1])
                {
                    if (has_v)
                        ft_printf("#env unset:\t %s\n", argv[i + 1]);
                    delete_line_env(argv[i + 1], &copy_env);
                    i++;
                }
                else
                {
                    ft_putstr("env: option requires an argument -- u\n");
                    return (0);
                }
            }
            i++;
        }
        ft_print_env(copy_env);
        // par rapport à argv on va setenv, ou autre ...



        // ft_print_env(environ);
    }
    else if (pid < 0)
    {
        //bug
    }
    else
    {
        //father
        wait(NULL);
    }

    return (0);
}