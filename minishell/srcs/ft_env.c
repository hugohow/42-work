#include "ft_env.h"


typedef struct s_token_env
{
    char *type;
    char flag_type;
    char *string;
}               t_token_env;

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

t_token_env *create_token_env(char *type, char flag_type, char *string)
{
    t_token_env *token_env;

    token_env = malloc(sizeof(t_token_env));
    token_env->type = type;
    token_env->flag_type = flag_type;
    token_env->string = string;   
    return (token_env);
}

int is_option(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '=')
            return (1);
        i++;
    }
    return (0);
}

t_token_env **tokenize_argv(int argc, char **argv)
{
    int i;
    int j;
    int k;
    t_token_env **list;
    char *utility;

    list = (t_token_env **)malloc((argc + 3) * sizeof(t_token_env *));
    i = 0;
    k = 0;
    utility = "";
    while (i < argc)
    {

        ft_printf("argv[i] : %s\n", argv[i]);
        if (i == 0)
        {
            list[k++] = create_token_env("command", 0, argv[0]);
        }
        else if (argv[i][0] && argv[i][0] == '-')
        {
            j = 1;
            while (argv[i][j])
            {
                if (argv[i][j] == 'i')
                    list[k++] = create_token_env("flag", 'i', NULL);
                else if (argv[i][j] == 'v')
                    list[k++] = create_token_env("flag", 'v', NULL);
                else if (argv[i][j] == 'P')
                {
                    if (argv[i + 1] && argv[i + 1][0] != '-')
                    {
                        list[k++] = create_token_env("flag", 'P', argv[i + 1]);
                        i++;
                    }
                    else
                    {
                        ft_printf("Error P n'a pas de path\n");
                        exit(0);
                    }
                }
                else if (argv[i][j] == 'S')
                {
                    if (argv[i + 1] && argv[i + 1][0] != '-')
                    {
                        list[k++] = create_token_env("flag", 'S', argv[i + 1]);
                        i++;
                    }
                    else
                    {
                        ft_printf("Error S n'a pas de path\n");
                        exit(0);
                    }
                }
                else if (argv[i][j] == 'u')
                {
                    if (argv[i + 1] && argv[i + 1][0] != '-')
                    {
                        list[k++] = create_token_env("flag", 'u', argv[i + 1]);
                        i++;
                    }
                    else
                    {
                        ft_printf("Error u n'a pas de path\n");
                        exit(0);
                    }
                }
                else
                {
                    ft_printf("Illegal option %c !\n", argv[i][j]);
                    exit(0);
                }
                j++;
            }
        }
        else
        {
            while (is_option(argv[i]))
            {
                list[k++] = create_token_env("option", 0, argv[i]);
                i++;
            }
            while (argv[i])
            {
                utility = ft_strjoin(utility, " ");
                utility = ft_strjoin(utility, argv[i]);
                i++;
            }
            list[k++] = create_token_env("utility", 0, utility);
        }

        i++;
    }
    list[k] = 0;
    return (list);
}

void print_token_ls(t_token_env **token_ls)
{
    int i;

    i = 0;
    while (token_ls[i] != 0)
    {
        ft_printf("type : %s \t flag: %c \t string : %s\n", token_ls[i]->type, token_ls[i]->flag_type, token_ls[i]->string);
        i++;
    }
}

int ft_env(int argc, char **argv, char ***p_environ)
{
    pid_t pid;

    char **copy_env;

    t_token_env **token_ls;

    if (argc == 1)
    {
        ft_print_env(*p_environ);
        return (0);
    }
    pid = fork();
    if (pid == 0)
    {
        token_ls = tokenize_argv(argc, argv);
        print_token_ls(token_ls);
        copy_env = copy_environ(*p_environ);
        // prepare_command("ls", copy_env);
        exit(0);
    }
    else if (pid < 0)
    {
        ft_printf("erreur pid");
        exit(0);
    }
    else
    {
        //father
        wait(NULL);
    }
    return (0);
}