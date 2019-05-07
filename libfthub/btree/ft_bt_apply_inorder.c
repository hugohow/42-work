/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_apply_inorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:02:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/07 12:14:10 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	ft_bt_apply_inorder(t_node_bt *root, void (*f)(t_node_bt *))
{
	if (root == NULL)
		return ;
	ft_bt_apply_inorder(root->left, f);
	f(root);
	ft_bt_apply_inorder(root->right, f);
}