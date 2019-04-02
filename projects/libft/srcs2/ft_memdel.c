/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:05:14 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:11:17 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void    ft_memdel(void **ap)
{
    if (ap == NULL)
       return ;
    free(*ap);
    *ap = NULL;
}