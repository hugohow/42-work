#include <stdio.h>

int ft_printf(const char* format, ...);

int main(int argc, char **argv)
{
    printf("test ft_printf: \n");
    printf("-----------------------------\n");
    printf("ft_printf: \n");
    printf("-----------------------------\n");
    ft_printf("ok %s\n%s\n%s\n", "ok1", "ok2", "ok3");
    printf("-----------------------------\n");
    printf("printf: \n");
    printf("-----------------------------\n");
    printf("ok %s\n%s\n%s\n", "ok1", "ok2", "ok3");
    printf("-----------------------------\n");
    return (0);
}