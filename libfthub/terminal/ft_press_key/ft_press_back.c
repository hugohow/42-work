/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:02:11 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 23:28:27 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_back(t_cmd **p_cmd, t_list **p_stack)
{	
	(void)p_stack;
	if ((*p_cmd)->cursor_index == 0)
		return (1);
	if (ft_get_col(p_cmd) == 0)
	{
		ft_clear_cmd(p_cmd);
	}
	if ((*p_cmd)->cursor_index > 0)
	{
		(*p_cmd)->cmd_str = ft_strjoin(ft_strsub((*p_cmd)->cmd_str, 0, (*p_cmd)->cursor_index - 1), 
		(*p_cmd)->cmd_str + (*p_cmd)->cursor_index);
		(*p_cmd)->cursor_index = (*p_cmd)->cursor_index - 1;
	}
	(*p_cmd)->brackets_closed = ft_str_brackets_is_valid((*p_cmd)->cmd_str, ft_strlen((*p_cmd)->cmd_str));
	(*p_cmd)->search_mode = 0;
	ft_print_cmd(p_cmd);
	return (1);
}