void ft_putstr_fd(char const *str, int fd);

void ft_putendl_fd(char const *str, int fd)
{
    ft_putstr_fd(str, fd);
    ft_putstr_fd("\n", fd);
}