#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

void test_memalloc();


int main(int argc, char **argv)
{

    printf("--------------------------------------------  \n\n");
    test_memalloc();
    return (0);
}

void test_memalloc()
{
    void *p;

    printf("Test ft_memalloc  \n\n");

    p = ft_memalloc(20);
    *(int *)p = 10;
    *(int *)(p + 1) = 10;
    free(p);
    p = ft_memalloc(20);
    printf("result attendu :\t %d \n", 0);
    printf("result :\t\t %d \n", *(int *)p);
    printf("result attendu :\t %d \n", 0);
    printf("result :\t\t %d \n", *(int *)(p + 1));
}
