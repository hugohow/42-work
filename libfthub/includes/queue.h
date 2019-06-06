/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:42:33 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 13:11:16 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "libft.h"

typedef struct		s_queue
{
	struct s_list	*head;
	struct s_list	*tail;
	size_t			size;
}					t_queue;

t_queue				*ft_queue_init(void);
int					ft_queue_enqueue(t_queue **p_queue, void const *content, \
	size_t content_size);
int					ft_queue_dequeue(t_queue **p_queue);
#endif
