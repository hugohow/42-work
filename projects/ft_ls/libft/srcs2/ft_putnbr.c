void    ft_putstr(char const *str);
void    ft_putchar(char c);

void    ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putstr("-2147483648");
        return ;
    }
    if (nb < 0)
    {
        nb = -nb;
        ft_putstr("-");
    }
    if (nb < 10)
    {
        ft_putchar(nb + '0');
    }
    else
    {
        ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + '0');
    }
}