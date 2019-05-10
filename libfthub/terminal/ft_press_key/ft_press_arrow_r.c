/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_arrow_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:39:21 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/10 11:03:22 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_arrow_r(t_cmd **p_cmd, t_cmd **cmd_historic)
{	
	(void)cmd_historic;
	if ((*p_cmd)->cursor_index + 1 > (int)ft_strlen((*p_cmd)->cmd_str))
		return (1);
	(*p_cmd)->cursor_index = (*p_cmd)->cursor_index + 1;
	return (1);
}