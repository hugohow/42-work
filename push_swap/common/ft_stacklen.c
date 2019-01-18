#include "common.h"

size_t ft_stacklen(t_stack **stack)
{
    if (*stack)
        return ((*stack)->len);
    return (0);
}