#include "common.h"

int post_analyse_stacks(t_stack **stack_a, t_stack **stack_b)
{
    size_t i;
    size_t len;
    long long *list;
    ft_putstr("\n\n");
    ft_putstr("---------Stack A---------\n");
    print_stack(*stack_a);
    ft_putstr("---------Stack B---------\n");
    print_stack(*stack_b);

    if (ft_stacklen(stack_b) != 0)
    {
        ft_putstr("KO\n");
        return (0);
    }
    list = (*stack_a)->list;
    len = ft_stacklen(stack_a);
    i = 0;
    if (len == 0)
        return (1);
    while (i < len - 1)
    {
        if (list[i] > list[i + 1])
        {
            printf("KO\n");
            return (0);
        }
        i++;
    }
    printf("OK\n");
    return (1);
}