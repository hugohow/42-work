/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:14:45 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 14:16:33 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_display(t_list **stack_top, void (*ft_print)(t_list *node))
{
	t_list *node;

	if (stack_top == NULL || *stack_top == NULL)
	{
		ft_putstr("Stack is empty\n");
		return ;
	}
	else
	{
		node = *stack_top;
		while (node)
		{
			ft_print(node);
			node = node->next;
		}
	}
}