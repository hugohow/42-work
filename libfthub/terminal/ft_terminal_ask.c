/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_ask.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:36:14 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 22:22:43 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int	ft_terminal_ask(t_cmd **p_cmd)
{
	int	 ret;
	int	 result;
	static t_list **stack_historic;

	if (stack_historic == NULL)
		stack_historic = ft_stack_init();
	if (p_cmd == NULL || *p_cmd == NULL)
		return (-1);
	ft_refresh_screen(p_cmd);
	ret = ft_read_key();
	(*p_cmd)->last_key = ret;
	result = (*(ft_apply_press(ret)))(p_cmd, stack_historic);
	return (result);
}
