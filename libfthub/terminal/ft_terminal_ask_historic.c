/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_ask_historic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:52:35 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/13 22:36:36 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int	ft_terminal_ask_historic(t_cmd **p_cmd, t_list **p_stack)
{
	int	 k;
	int ret;

	k = 0;
	ret = 0;
	(void)p_stack;
	while ((*p_cmd)->search_mode == 1 && k >= 0)
	{
		if (ret == 0)
			ret = (*p_cmd)->last_key;
		else
			ret = ft_read_key();
		// printf("k : %d str : %s\n", k, (cmd_historic[k])->cmd_str);
		printf("%d\n", k);
		// if (cmd_historic[k])
		// 	printf("%s\n", (cmd_historic[k])->cmd_str);
		
		if (ret == ARROW_UP)
			k++;
		else if (ret == ARROW_DOWN)
			k--;
		else
			(*p_cmd)->search_mode = 0;
	}
	return (1);
}