#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char* format, ...);

int main(int argc, char **argv)
{
    // printf("%+012.1d", 42);
    // ft_printf("%+012.1d", 42);
    // ft_printf("\n\n");

    printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
    ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
    ft_printf("\n\n");
    // printf("%#07.4lX !", 10);
    // ft_printf("%#07.4lX !", 10);
    // ft_printf("\n\n");
    return (0);
}
