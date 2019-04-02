#include "prepare_command.h"


int is_separator(char *str)
{
    if (str[0] && str[0] == ';')
        return (1);
    if (str[0] && str[0] == '<')
        return (1);
    return (0);
}


void print_tokens(t_token **list)
{
    int i;

    i = 0;
    while (list[i])
    {
        ft_printf("type : %s, value : %s\n", list[i]->type, list[i]->value);
        i++;
    }
}

t_token **tokenize_command(char *cmd)
{
    t_token **list;
    t_token *token;
    int i;
    int k;
    int len;
    char *value;

    list = (t_token **)malloc(1000*sizeof(t_token *));
    i = 0;
    k = 0;
    while (cmd[i])
    {
        token = malloc(sizeof(t_token));
        if (is_separator(cmd + i) == 0)
        {
            value = malloc(((ft_strlen(cmd) + 1) * sizeof(char)));
            len = 0;
            while (cmd[i] && is_separator(cmd + i) == 0)
            {
                value[len] = cmd[i];
                len++;
                i++;
            }
            value[len] = '\0';
            token->value = value;
            if (is_exit(value) == 1)
                token->type = "exit";
            else
                token->type = "cmd";
            list[k] = token;
            k++;
        }
        else if (is_separator(cmd + i))
        {
            token->type = "separator";
            token->value = ft_strsub(cmd, i, 1);
            list[k] = token;
            k++;
            i++;
        }
    }
    list[k] = 0;
    // print_tokens(list);
    return (list);
}

int prepare_command(char *cmd, char ***copy_env, int prev_res, struct termios *p_orig_termios)
{
    t_token **list;
    int i;
    int success;

    list = tokenize_command(cmd);
    i = 0;
    success = prev_res;
    while (list[i])
    {
        if (ft_strcmp(list[i]->type, "exit") == 0)
            ft_exit(list[i]->value, success, p_orig_termios);
        else if (ft_strcmp(list[i]->type, "separator") != 0)
            success = execute_command(list[i]->value, get_paths(*copy_env), copy_env, p_orig_termios, 0, 1, 2);
        i++;
    }
    return (success);
}