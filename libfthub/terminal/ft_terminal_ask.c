/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_ask.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:36:14 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/10 11:04:33 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static const	t_ft_press_key fts_press[] =
{
	{9, &ft_press_tab},
	{10, &ft_press_enter},
	{127, &ft_press_back},
	{ARROW_LEFT, &ft_press_arrow_l},
	{ARROW_RIGHT, &ft_press_arrow_r},
	{0, &ft_press_printable_char},
	{0, NULL},
};

t_ft_press *ft_find_ft(int ret)
{
	int			i;

	i = 0;
	while (fts_press[i].key)
	{
		if (fts_press[i].key == ret)
			break ;
		i++;
	}
	return (fts_press[i].ft);
}

int	ft_terminal_ask(t_cmd **p_cmd, t_cmd **cmd_historic)
{
	int	 ret;
	int	 result;
	// char *tmp;
	
	(void)cmd_historic;
	if (p_cmd == NULL || *p_cmd == NULL)
		return (-1);
	ft_refresh_screen(p_cmd);
	ret = ft_read_key();
	(*p_cmd)->last_key = ret;
	result = (*(ft_find_ft(ret)))(p_cmd, cmd_historic);


	// if (isatty(0) == 0)
	// {
	// 	tmp = ft_strdup((*p_cmd)->cmd_str);
	// 	if (tmp == NULL)
	// 		return (-1);
	// 	ret = get_next_line(fd, &tmp);
	// 	(*p_cmd)->cmd_str = tmp;
	// }
	// else
	// {
	// }
	return (result);
}
