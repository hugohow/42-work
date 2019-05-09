/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:38:15 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 13:54:29 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_pop(t_list **stack_top)
{
	t_list *node;

	if (stack_top == NULL || *stack_top == NULL)
	{
		return ;
	}
	else
	{
		node = *stack_top;
		*stack_top = (*stack_top)->next;
		node->next = NULL;
		ft_memdel((void **)&(node->content));
		ft_memdel((void **)&node);
	}
}