#include <string.h>

void ft_putstr(char const *str);

void ft_putendl(char const *str)
{
    if (str == NULL)
        return ;
    ft_putstr(str);
    ft_putstr("\n");
}