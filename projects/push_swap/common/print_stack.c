#include "common.h"

void print_stack(t_stack *stack)
{
    size_t i;

    i = 0;
    while (i < stack->len)
    {
        ft_printf("%lld\n", (stack->list)[i]);
        i++;
    }
}