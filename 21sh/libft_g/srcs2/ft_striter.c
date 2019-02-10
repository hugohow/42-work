#include <string.h>

void ft_striter(char *s, void (*f)(char *))
{
    if (s == NULL)
		return ;
    while (*s)
    {
        f(s);
        s++;
    }
}