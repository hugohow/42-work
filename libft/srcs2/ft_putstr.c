void ft_putchar(char c);

void ft_putstr(char const *str)
{
    while (*str)
        ft_putchar(*str++);
}