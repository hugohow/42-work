#include <unistd.h>
#include <string.h>

size_t ft_strlen(const char *str);

void ft_putstr(char const *str, int fd)
{
    if (str == NULL)
        return ;
    write(fd, str, ft_strlen(str));
}
