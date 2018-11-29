void ft_putchar_fd(char c, int fd);

void ft_putstr_fd(char const *str, int fd)
{
    while (*str)
        ft_putchar_fd(*str++, fd);
}