#include "ft_malloc.h"
#include <stdio.h>

int main(void)
{
	char *output;

    printf("Hello, world !\n");

	output = (char *)ft_malloc(111);
	ft_free(output);
	output = NULL;
    return 0;    
}
