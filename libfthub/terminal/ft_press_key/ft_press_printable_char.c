/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_printable_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:53:34 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 23:14:27 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_printable_char(t_cmd **p_cmd, t_list **p_stack)
{
	(void)p_stack;
        (*p_cmd)->cmd_str = ft_strjoin(
            ft_strjoin(ft_strsub((*p_cmd)->cmd_str, 0, (*p_cmd)->cursor_index), (char *)&((*p_cmd)->last_key)), 
            (*p_cmd)->cmd_str + (*p_cmd)->cursor_index);
	(*p_cmd)->cursor_index = (*p_cmd)->cursor_index + 1;
	(*p_cmd)->brackets_closed = ft_str_brackets_is_valid((*p_cmd)->cmd_str, ft_strlen((*p_cmd)->cmd_str));
	(*p_cmd)->search_mode = 0;
	return (1);
}