
void    ft_putstr_fd(char const *str, int fd);
void    ft_putchar_fd(char c, int fd);

void    ft_putnbr_fd(int nb, int fd)
{
    if (nb == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
        return ;
    }
    if (nb < 0)
    {
        nb = -nb;
        ft_putstr_fd("-", fd);
    }
    if (nb < 10)
    {
        ft_putchar_fd(nb + '0', fd);
    }
    else
    {
        ft_putnbr_fd(nb / 10, fd);
        ft_putchar_fd(nb % 10 + '0', fd);
    }
}