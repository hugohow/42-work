#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>      /* wint_t */

int ft_printf(const char* format, ...);

int main(void)
{
    printf("%d", -2147483647);
    ft_printf("%d", -2147483647);
    ft_printf("\n\n");
    return 0;
}




// int main(int argc, char **argv)
// {
//     // printf("%+012.1d", 42);
//     // ft_printf("%+012.1d", 42);
//     // ft_printf("\n\n");

//     printf("hello ca%-4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
//     // ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
//     // ft_printf("\n\n");


//     // printf("%#07.4lX !", 10);
//     // ft_printf("%#07.4lX !", 10);
//     // ft_printf("\n\n");
//     return (0);
// }
