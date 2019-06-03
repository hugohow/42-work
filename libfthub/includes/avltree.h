/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:24:03 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 12:37:45 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_H
# define AVLTREE_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct				s_node_avlt
{
	void					*content;
	size_t					content_size;
	struct s_node_avlt		*left;
	struct s_node_avlt		*right;
	int						height;
}							t_node_avlt;

t_node_avlt					*ft_avlt_add(t_node_avlt **p_root, void *content, \
	size_t content_size, int (*cmp)(t_node_avlt *, t_node_avlt *));
void						ft_avlt_apply_inorder(t_node_avlt *root, \
	void (*f)(t_node_avlt *));
void						ft_avlt_apply_postorder(t_node_avlt *root, \
	void (*f)(t_node_avlt *));
t_node_avlt					*ft_avlt_create(void *content, size_t content_size);
void						ft_avlt_free(t_node_avlt **p_root);
t_node_avlt					*ft_avlt_insert(t_node_avlt **p_root, \
	t_node_avlt *node, int (*cmp)(t_node_avlt *, t_node_avlt *));
int							ft_avlt_is_valid(t_node_avlt *root);
t_node_avlt					*ft_avlt_left_rot(t_node_avlt *node);
t_node_avlt					*ft_avlt_right_rot(t_node_avlt *node);
#endif
