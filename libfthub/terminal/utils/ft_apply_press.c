/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:21:14 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 22:22:12 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static const	t_ft_press_key fts_press[] =
{
	{9, &ft_press_tab},
	{10, &ft_press_enter},
	{127, &ft_press_back},
	{ARROW_LEFT, &ft_press_arrow_left},
	{ARROW_RIGHT, &ft_press_arrow_right},
	{ARROW_UP, &ft_press_arrow_up},
	{ARROW_DOWN, &ft_press_arrow_down},
	{0, &ft_press_printable_char},
	{0, NULL},
};

t_ft_press *ft_apply_press(int ret)
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