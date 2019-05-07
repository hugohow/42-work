/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:24:03 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/07 13:42:13 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_node_bt 
{
	void 					*content;
	size_t					content_size;
	struct s_node_bt		*left;
	struct s_node_bt		*right;
}				t_node_bt;


t_node_bt	*ft_bt_add(t_node_bt **p_root, void *content, size_t content_size, int (*cmp)(t_node_bt *, t_node_bt *));
void		ft_bt_apply_inorder(t_node_bt *root, void (*f)(t_node_bt *));
void		ft_bt_apply_postorder(t_node_bt *root, void (*f)(t_node_bt *));
t_node_bt	*ft_bt_create(void *content, size_t content_size);
void		ft_bt_free(t_node_bt **p_root);
t_node_bt	*ft_bt_insert(t_node_bt **p_root, t_node_bt *node, int (*cmp)(t_node_bt *, t_node_bt *));
int			ft_bt_is_valid(t_node_bt *root);
#endif