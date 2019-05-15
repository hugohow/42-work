/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_arrow_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:15:44 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 23:41:45 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_arrow_down(t_cmd **p_cmd, t_list **p_stack)
{
	if (ft_get_row_from_bottom(p_cmd) == 0)
	{
		(*p_cmd)->search_mode = 1;
		return (ft_terminal_ask_historic(p_cmd, p_stack));
	}
	else
	{

	}
	return (1);
}