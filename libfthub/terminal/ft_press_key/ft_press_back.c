/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:02:11 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/13 22:31:47 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_back(t_cmd **p_cmd, t_list **p_stack)
{	
	(void)p_stack;
	if ((*p_cmd)->cursor_index == 0)
		return (1);
	if (ft_get_col(p_cmd) == 0)
		return (1);
	if ((*p_cmd)->cursor_index > 0)
	{
		(*p_cmd)->cmd_str = ft_strjoin(ft_strsub((*p_cmd)->cmd_str, 0, (*p_cmd)->cursor_index - 1), 
			(*p_cmd)->cmd_str + (*p_cmd)->cursor_index);
		(*p_cmd)->cursor_index = (*p_cmd)->cursor_index - 1;
	}
	(*p_cmd)->brackets_closed = ft_str_brackets_is_valid((*p_cmd)->cmd_str, ft_strlen((*p_cmd)->cmd_str));
	(*p_cmd)->search_mode = 0;
	(*p_cmd)->search_index = 0;
	return (1);
}