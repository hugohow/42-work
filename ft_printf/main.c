#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char* format, ...);

int main(int argc, char **argv)
{
    char *p;
    p = (char *)malloc(3);
    // printf("test ft_printf: \n");

    // %[flags][width][.precision][length]specifier
    
    // printf("-----------------------------\n");
    // printf("printf attendu: \n");
    // printf("ok %s%s%s\t%q%s\n", "ok1", "ok2", "ok3", "ok4");
    // printf("ft_printf: \n");
    ft_printf("pointeur : %p", p);
    printf("pointeur : %p", p);
    // printf("-----------------------------\n");
    // int number    =  5;
    // char *pointer = "little";

    // printf("Here is a number-%4d-and a-%10s-word.\n", number, pointer);
    return (0);
}