#include "common.h"

void print_stack(char **stack)
{
    int i;

    i = 0;
    while (stack[i])
    {
        ft_putstr(stack[i]);
        ft_putchar('\n');
        i++;
    }
}