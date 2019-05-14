/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_arrow_right.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:39:21 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/13 22:31:34 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_arrow_right(t_cmd **p_cmd, t_list **p_stack)
{	
	(void)p_stack;
	if ((*p_cmd)->cursor_index + 1 > (int)ft_strlen((*p_cmd)->cmd_str))
		return (1);
	(*p_cmd)->cursor_index = (*p_cmd)->cursor_index + 1;
	(*p_cmd)->search_mode = 0;
	(*p_cmd)->search_index = 0;
	return (1);
}