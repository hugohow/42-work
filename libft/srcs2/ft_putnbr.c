void    ft_putstr(char const *str);
char    *ft_itoa(int nb);

void    ft_putnbr(int nb)
{
    ft_putstr(ft_itoa(nb));
}