/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_prompt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:03:44 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 16:30:15 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

// int ft_terminal_prompt(const char* format, ...) soon

int ft_terminal_prompt(int fd, const char *str)
{
	ft_putstr_fd(str, fd);
	return (1);
}
