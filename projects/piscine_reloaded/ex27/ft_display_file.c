/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:43:49 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 22:56:37 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prot.h"

int	main(int argc, char **argv)
{
	if (ft_check_param_num(argc))
		ft_read_file(argv[1]);
	return (0);
}
