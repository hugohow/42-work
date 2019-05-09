/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:03:50 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 16:10:21 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void ft_terminal_exit(t_config *old_config)
{
    tcsetattr(0, TCSAFLUSH, old_config);
	exit(0);
}
