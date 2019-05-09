/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_ask.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:36:14 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 19:16:59 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

// typedef struct	s_cmd
// {
// 	char *cmd_str;
// 	int  cursor_index;
// 	int  last_key;
//  t_choice **choices;
// }				t_cmd;

int	ft_terminal_ask(int fd, t_cmd **p_cmd, t_cmd **cmd_historic)
{
	int	 ret;
	char *tmp;
	
	(void)cmd_historic;
	if (p_cmd == NULL || *p_cmd == NULL)
		return (-1);
	ft_putstr_fd((*p_cmd)->cmd_str, fd);
	tmp = ft_strdup((*p_cmd)->cmd_str);
	if (tmp == NULL)
		return (-1);
	if (isatty(0) == 1)
	{
		ret = ft_read_key();
		(*p_cmd)->last_key = ret;
		if (ft_isprint(ret))
			tmp = ft_strjoin(tmp, (char *)&ret);
	}
	else
	{
		ret = get_next_line(fd, &tmp);
	}
	(*p_cmd)->cmd_str = tmp;
	return (1);
}
