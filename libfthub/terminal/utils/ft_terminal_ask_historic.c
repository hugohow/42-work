/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_ask_historic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:52:35 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 23:15:07 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"


t_list *get_nth_node(t_list *stack, int k)
{
	t_list *node;

	if (k == -1)
		return (NULL);
	node = stack;
	while (k != 0)
	{
		if (node == NULL)
			break;
		node = node->next;
		k--;
	}
	return (node);
}

void visualize_cmd(t_cmd **p_cmd, t_list **p_stack, int k)
{
	t_list *node;
	
	ft_clear_cmd(p_cmd);
	node = get_nth_node(*p_stack, k);
	if (node && node->content)
	{
		(*p_cmd)->cmd_str = ft_strdup(((t_cmd *)(node->content))->cmd_str);
		(*p_cmd)->cursor_index = (int)ft_strlen(((t_cmd *)(node->content))->cmd_str);
	}
	else
	{
		(*p_cmd)->cmd_str = ft_strdup("");
		(*p_cmd)->cursor_index = 0;
	}
	ft_print_cmd(p_cmd);
}


int	ft_terminal_ask_historic(t_cmd **p_cmd, t_list **p_stack)
{
	int	 k;
	int ret;

	ret = (*p_cmd)->last_key;
	k = ret == ARROW_UP ? 0 : -1;
	while ((ret == ARROW_UP || ret == ARROW_DOWN))
	{
		visualize_cmd(p_cmd, p_stack, k);
		ret = ft_read_key();
		if (ret == ARROW_UP)
			k++;
		if (ret == ARROW_DOWN && k > 0)
			k--;
	}
	(*p_cmd)->last_key = ret;
	(*p_cmd)->search_mode = 0;
	return (*(ft_apply_press(ret)))(p_cmd, p_stack);
}