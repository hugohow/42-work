void    ft_putstr_fd(char const *str, int fd);
char    *ft_itoa(int nb);

void    ft_putnbr_fd(int nb, int fd)
{
    ft_putstr_fd(ft_itoa(nb), fd);
}