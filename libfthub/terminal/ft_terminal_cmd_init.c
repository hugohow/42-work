/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_cmd_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:54:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/13 18:33:21 by hhow-cho         ###   ########.fr       */
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


t_cmd *ft_terminal_cmd_init(const char *str)
{
	t_cmd *cmd;
	size_t len;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	len = ft_strlen(str);
	cmd->cmd_str = ft_strdup(str);
	cmd->cursor_index = (int)len;
	cmd->last_key = len > 0 ? (int)str[ft_strlen(str) - 1] : 0;
	cmd->choices = NULL;
	cmd->brackets_closed = ft_str_brackets_is_valid(cmd->cmd_str, ft_strlen(cmd->cmd_str));
	return (cmd);
}