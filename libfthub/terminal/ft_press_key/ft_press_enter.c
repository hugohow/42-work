/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_enter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:52:55 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/13 22:35:10 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_enter(t_cmd **p_cmd, t_list **p_stack)
{
	// int k;

	if ((*p_cmd)->brackets_closed == 1)
		return (0);

	(*p_cmd)->cmd_str = ft_strjoin(
		ft_strjoin(ft_strsub((*p_cmd)->cmd_str, 0, (*p_cmd)->cursor_index), (char *)&((*p_cmd)->last_key)), 
		(*p_cmd)->cmd_str + (*p_cmd)->cursor_index);
	ft_putstr("\r\n");
	(*p_cmd)->cursor_index = (*p_cmd)->cursor_index + 1;
	(*p_cmd)->brackets_closed = ft_str_brackets_is_valid((*p_cmd)->cmd_str, ft_strlen((*p_cmd)->cmd_str));
	ft_stack_push(p_stack, (void const *)(*p_cmd), sizeof(t_cmd *));
	// k = 0;
	// *(cmd_historic + k) = ft_memalloc(sizeof(t_cmd));
	// // cmd_historic[k] = ft_memcpy(cmd_historic[k], *p_cmd, sizeof(t_cmd));
	// k++;
	// *(cmd_historic + k) = ft_memalloc(sizeof(t_cmd));
	// k++;
	// *(cmd_historic + k) = NULL;
	(*p_cmd)->search_mode = 0;
	(*p_cmd)->search_index = 0;
	// (*p_cmd)->cmd_str = ft_strjoin((*p_cmd)->cmd_str, "\n");
	return (1);
}