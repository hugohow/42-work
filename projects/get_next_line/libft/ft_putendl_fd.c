/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:05:37 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 18:02:10 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	if (str == NULL)
		return ;
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\n", fd);
}
