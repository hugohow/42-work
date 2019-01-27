#include <string.h>

void    ft_strclr(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
		*s++ = '\0';
}