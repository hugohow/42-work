/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:35:03 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 14:00:52 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	**ft_stack_init(void)
{
	t_list **stack;

	stack = (t_list	**)malloc(sizeof(t_list	*));
	if (stack == NULL)
		return (NULL);
	*stack = NULL;
	return (stack);
}