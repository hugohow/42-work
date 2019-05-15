/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_arrow_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:15:47 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 19:16:13 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_arrow_up(t_cmd **p_cmd, t_list **p_stack)
{
	// int k;
	// t_cmd *cmd;
	
	if (ft_get_row(p_cmd) == 0)
	{
		(*p_cmd)->search_mode = 1;
		ft_terminal_ask_historic(p_cmd, p_stack);
		return (1);
	}
	else
	{

	}
	return (1);
}