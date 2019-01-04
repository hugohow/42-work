#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char* format, ...);

int main(int argc, char **argv)
{
    ft_printf("%.0i\n", 0);
    printf("%.0i\n", 0);
    ft_printf("\n\n");
    ft_printf("%.d\n", 0);
    printf("%.d\n", 0);
    ft_printf("\n\n");
    ft_printf("%00+10.4d\n", 0);
    printf("%00+10.4d\n", 0);
    ft_printf("\n\n");
    ft_printf("%20.ld et %.4hhi !\n", 0x11ffaa147, (signed char)-8);
    printf("%20.ld et %.4hhi !\n", 0x11ffaa147, (signed char)-8);
    ft_printf("\n\n");
    ft_printf("% 20.12ld et % 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
    printf("% 20.12ld et % 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
    ft_printf("\n\n");
    ft_printf("toto%.0d et %+.i et  %   .0D !!!\n", 0, 0, 0);
    printf("toto%.0d et %+.i et  %   .0D !!!\n", 0, 0, 0);
    ft_printf("\n\n");
    ft_printf("hello % .d this is a test", 0);
    printf("hello % .d this is a test", 0);
    ft_printf("\n\n");
    ft_printf("%U", 231009999);
    printf("%U", 231009999);
    ft_printf("\n\n");
    ft_printf("%zu", (size_t)-145612220);
    printf("%zu", (size_t)-145612220);
    ft_printf("\n\n");
    ft_printf("%.u", 0);
    printf("%.u", 0);
    // printf("pointeur : %-020.10p", p);
    // printf("-----------------------------\n");
    // int number    =  5;
    // char *pointer = "little";

    // printf("Here is a number-%4d-and a-%10s-word.\n", number, pointer);
    return (0);
}
