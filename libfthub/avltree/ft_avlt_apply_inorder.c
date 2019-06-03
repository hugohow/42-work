/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlt_apply_inorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:42:20 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 12:41:30 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

void	ft_avlt_apply_inorder(t_node_avlt *root, void (*f)(t_node_avlt *))
{
	if (root == NULL)
		return ;
	ft_avlt_apply_inorder(root->left, f);
	f(root);
	ft_avlt_apply_inorder(root->right, f);
}
