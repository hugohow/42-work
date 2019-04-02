#include <unistd.h>
#include <string.h>

size_t ft_strlen(const char *str);

void ft_putstr(char const *str)
{
    if (str == NULL)
        return ;
    write(1, str, ft_strlen(str));
}