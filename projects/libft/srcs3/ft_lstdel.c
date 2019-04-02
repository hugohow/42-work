/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:13:13 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 17:13:14 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    if (*alst)
    {
        del((*alst)->content, (*alst)->content_size);
        ft_lstdel(&((*alst)->next), del);
    }
    else
        return ;
    free(*alst);
    *alst = NULL; 
}
