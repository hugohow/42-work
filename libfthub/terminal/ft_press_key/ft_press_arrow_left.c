/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_arrow_left.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:40:36 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/13 22:31:32 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_arrow_left(t_cmd **p_cmd, t_list **p_stack)
{
	(void)p_stack;
	if ((*p_cmd)->cursor_index == 0)
		return (1);
	if (ft_get_col(p_cmd) == 0)
		return (1);
	(*p_cmd)->cursor_index = (*p_cmd)->cursor_index - 1;
	(*p_cmd)->search_mode = 0;
	(*p_cmd)->search_index = 0;
	return (1);
}