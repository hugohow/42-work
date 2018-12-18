#include <wchar.h>
#include <string.h>
#include <unistd.h>

void ft_wputchar(wchar_t c)
{
    write(1, &c, sizeof(c));
}

void ft_wputstr(wchar_t const *str)
{
    if (str == NULL)
        return ;
    while (*str != L'\0')
        ft_wputchar(*str++);
}
