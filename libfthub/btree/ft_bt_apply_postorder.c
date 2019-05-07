/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_apply_postorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:55:01 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/07 12:55:48 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	ft_bt_apply_postorder(t_node_bt *root, void (*f)(t_node_bt *))
{
	if (root == NULL)
		return ;
	ft_bt_apply_postorder(root->left, f);
	ft_bt_apply_postorder(root->right, f);
	f(root);
}