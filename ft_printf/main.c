#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char* format, ...);

int main(int argc, char **argv)
{
    // printf("%+012.1d", 42);
    // ft_printf("%+012.1d", 42);
    // ft_printf("\n\n");

    printf("t %#7.5X", 0xab);
    ft_printf("t %#7.5X", 0xab);
    ft_printf("\n\n");
    // printf("%#07.4lX !", 10);
    // ft_printf("%#07.4lX !", 10);
    // ft_printf("\n\n");
    return (0);
}
