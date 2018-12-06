#include <string.h>

void ft_putchar(char c);

void ft_putstr(char const *str)
{
    if (str == NULL)
        return ;
    while (*str)
        ft_putchar(*str++);
}