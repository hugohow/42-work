#include "stack.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
	t_list **stack;
	int a;
	int b;

	a = 10;
	b = 20;
	printf("-------------Test ft_stack_init-------------\n");
	stack = ft_stack_init();
	printf("\033[32mCheck if stack is inited \033[00m\n");
	assert(stack != NULL);
	assert(*stack == NULL);

	printf("-------------Test ft_stack_push-------------\n");
	ft_stack_push(stack, (const void *)&a, sizeof(a));
	ft_stack_push(stack, (const void *)&b, sizeof(b));
	ft_stack_push(stack, (const void *)&a, sizeof(a));
	ft_stack_push(stack, (const void *)&b, sizeof(b));
	printf("\033[32mCheck if stack is correct \033[00m\n");
	assert(stack != NULL);
	assert(*stack != NULL);
	printf("\033[32mCheck if value top is correct \033[00m\n");
	assert(stack != NULL);
	assert(*stack != NULL);
	assert(*((int *)((*stack)->content)) == b);
	printf("-------------Test ft_stack_pop-------------\n");
	ft_stack_pop(stack);
	printf("\033[32mCheck if value top is correct after 1 pop \033[00m\n");
	assert(stack != NULL);
	assert(*stack != NULL);
	assert(*((int *)((*stack)->content)) == a);
	ft_stack_pop(stack);
	printf("\033[32mCheck if value top is correct after 2 pop \033[00m\n");
	assert(stack != NULL);
	assert(*stack != NULL);
	assert(*((int *)((*stack)->content)) == b);
	ft_stack_pop(stack);
	printf("\033[32mCheck if value top is correct after 3 pop \033[00m\n");
	assert(stack != NULL);
	assert(*stack != NULL);
	assert(*((int *)((*stack)->content)) == a);
	ft_stack_pop(stack);
	printf("\033[32mCheck if value top is NULL \033[00m\n");
	assert(stack != NULL);
	assert(*stack == NULL);
	ft_stack_pop(stack);
	printf("\033[32mCheck if value top is NULL \033[00m\n");
	assert(stack != NULL);
	assert(*stack == NULL);
	ft_stack_pop(stack);
	printf("\033[32mCheck if value top is NULL \033[00m\n");
	assert(stack != NULL);
	assert(*stack == NULL);
	return (0);
}
