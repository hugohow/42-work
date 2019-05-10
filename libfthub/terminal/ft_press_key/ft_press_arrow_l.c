/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_arrow_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:40:36 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/10 11:03:15 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_arrow_l(t_cmd **p_cmd, t_cmd **cmd_historic)
{
	(void)cmd_historic;
	if ((*p_cmd)->cursor_index == 0)
		return (1);
	if (ft_get_col(p_cmd) == 0)
		return (1);
	(*p_cmd)->cursor_index = (*p_cmd)->cursor_index - 1;
	return (1);
}