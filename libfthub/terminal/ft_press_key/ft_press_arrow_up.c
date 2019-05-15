/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_arrow_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:15:47 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 22:23:34 by hhow-cho         ###   ########.fr       */
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
		return (ft_terminal_ask_historic(p_cmd, p_stack));
	}
	else
	{

	}
	return (1);
}