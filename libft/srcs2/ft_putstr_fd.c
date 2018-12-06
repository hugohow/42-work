#include <string.h>

void ft_putchar_fd(char c, int fd);

void ft_putstr_fd(char const *str, int fd)
{
    if (str == NULL)
        return ;
    while (*str)
        ft_putchar_fd(*str++, fd);
}