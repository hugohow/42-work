/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:23:51 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 23:02:51 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_press_tab(t_cmd **p_cmd, t_list **p_stack)
{
	(void)p_stack;
	if (p_cmd )
	{
		
	}
	(*p_cmd)->search_mode = 0;
	return (1);
	// ft_select
}