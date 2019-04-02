
int     ft_isalpha(int c);
int     ft_isdigit(int c);

int     ft_isalnum(int c)
{
    if (ft_isalpha(c) == 1)
        return (1);
    if (ft_isdigit(c) == 1)
        return (1);
    return (0);
}
