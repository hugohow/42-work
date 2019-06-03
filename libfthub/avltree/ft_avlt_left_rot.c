/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlt_left_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:54:00 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 12:43:25 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

static int	max(int a, int b)
{
	return (a > b ? a : b);
}

static int	get_height(t_node_avlt *node)
{
	if (node == NULL)
		return (0);
	return (node->height);
}

t_node_avlt	*ft_avlt_left_rot(t_node_avlt *root)
{
	t_node_avlt *pivot;
	t_node_avlt *y;

	if (root == NULL || root->right == NULL)
		return (root);
	pivot = root->right;
	y = pivot->left;
	pivot->left = root;
	root->right = y;
	root->height = 1 + max(get_height(root->left), get_height(root->right));
	pivot->height = 1 + max(get_height(pivot->left), get_height(pivot->right));
	return (pivot);
}
