/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:44:17 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 13:55:13 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_push(t_list **stack_top, void const *content, size_t content_size)
{
	t_list *node;

	if (stack_top == NULL)
		return ;
	node = ft_lstnew(content, content_size);
	if (node == NULL)
		return ;
	if (*stack_top)
		node->next = *stack_top;
	*stack_top = node;
}