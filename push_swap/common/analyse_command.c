#include "common.h"

void shift_plus_stack(t_stack **stack)
{
    size_t i;
    long long *list;

    i = ft_stacklen(stack);
    list = (*stack)->list;
    while (i > 0)
    {
        list[i] = list[i - 1];
        i--;
    }
    list[0] = 0;
    (*stack)->list = list;
}

void shift_minus_stack(t_stack **stack)
{
    size_t i;
    long long *list;
    size_t len;

    len = ft_stacklen(stack);
    list = (*stack)->list;
    i = 1;
    if (list[0])
    {
        while (i < len)
        {
            list[i - 1] = list[i];
            i++;
        }
        list[i - 1] = 0;
    }
    (*stack)->list = list;
}

void execute_p(t_stack **stack_dest, t_stack **stack_src)
{
    if (ft_stacklen(stack_src) > 0)
    {
        shift_plus_stack(stack_dest);

        ((*stack_dest)->list)[0] = ((*stack_src)->list)[0];

        shift_minus_stack(stack_src);
        ((*stack_src)->len)--;
        ((*stack_dest)->len)++;
        ft_putstr("Push\n");
        return ;
    }
    ft_putstr("Nothing to push\n");
}

void execute_s(t_stack **stack)
{
    //  intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
// rien s’il n’y en a qu’un ou aucun.
    int i;
    long long tmp;
    long long *list;
    i = 0;
    
    list = (*stack)->list;
    if (ft_stacklen(stack) > 1)
    {
        tmp = list[0];
        list[0] = list[1];
        list[1] = tmp;
        ft_putstr("invert\n");
    }
    else
    {
        ft_putstr("nothing to invert\n");
    }
}

void execute_rr(t_stack **stack)
{
    size_t length;
    long long *list;

    list = (*stack)->list;
    length = ft_stacklen(stack);
    if (length > 0)
    {
        shift_plus_stack(stack);
        list[0] = list[length];
        list[length] = 0;
        ft_putstr("Rotate reverse\n");
        return ;
    }
    ft_putstr("Nothing to rotate reverse\n");
}

void execute_r(t_stack **stack)
{
    size_t length;
    long long tmp;
    long long *list;

    length = ft_stacklen(stack);
    list = (*stack)->list;
    if (length > 0)
    {
        tmp = list[0];
        shift_minus_stack(stack);
        list[length - 1] = tmp;
        list[length] = 0;
        ft_putstr("Rotate\n");
        return ;
    }
    ft_putstr("Nothing to rotate\n");
}

void analyse_command(char *command, t_stack **stack_a, t_stack **stack_b)
{
    command = ft_strtrim(command);
    if (ft_strcmp(command, "sa") == 0)
    {
        // ft_putstr("sa\n");
        execute_s(stack_a);
    }
    else if (ft_strcmp(command, "sb") == 0)
    {
        // ft_putstr("sb\n");
        execute_s(stack_b);
    }
    else if (ft_strcmp(command, "ss") == 0)
    {
        // ft_putstr("ss\n");
        execute_s(stack_a);
        execute_s(stack_b);
    }
    else if (ft_strcmp(command, "pa") == 0)
    {
        execute_p(stack_a, stack_b);
        // ft_putstr("pa\n");
    }
    else if (ft_strcmp(command, "pb") == 0)
    {
        execute_p(stack_b, stack_a);
        // ft_putstr("pb\n");
    }
    else if (ft_strcmp(command, "ra") == 0)
    {
        execute_r(stack_a);
        // ft_putstr("ra\n");
    }
    else if (ft_strcmp(command, "rb") == 0)
    {
        execute_r(stack_b);
        // ft_putstr("rb\n");
    }
    else if (ft_strcmp(command, "rr") == 0)
    {
        execute_r(stack_a);
        execute_r(stack_b);
        // ft_putstr("rr\n");
    }
    else if (ft_strcmp(command, "rra") == 0)
    {
        execute_rr(stack_a);
        // ft_putstr("rra\n");
    }
    else if (ft_strcmp(command, "rrb") == 0)
    {
        execute_rr(stack_b);
        // ft_putstr("rrb\n");
    }
    else if (ft_strcmp(command, "rrr") == 0)
    {
        execute_rr(stack_a);
        execute_rr(stack_b);
        // ft_putstr("rrr\n");
    }
    else
    {
        // ft_putstr("unknown command\n");
    }
}