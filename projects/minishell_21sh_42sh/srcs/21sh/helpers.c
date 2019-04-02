int is_separator(char *str)
{
    if (str[0] && str[0] == ';')
        return (1);
    return (0);
}


int is_redirection(char *str)
{
    if (str[0] && str[0] == '<')
        return (1);
    return (0);
}

int is_pipe(char *str)
{
    if (str[0] && str[0] == ';')
        return (1);
    if (str[0] && str[0] == '<')
        return (1);
    return (0);
}
