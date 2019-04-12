/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:22:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/08 10:55:23 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *head)
{
	t_list *tmp;

	while (head != NULL)
	{
		tmp = head;
		if (tmp->content)
			free(tmp->content);
		tmp->content = NULL;
		tmp->content_size = 0;
		free(tmp);
		tmp = NULL;
		head = head->next;
	}
}
