#include <string.h>

void    ft_strclr(char *s)
{
	while (*s)
		*s++ = '\0';
}