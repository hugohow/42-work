/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlt_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:49:16 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 12:52:24 by hhow-cho         ###   ########.fr       */
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

static int	get_balance(t_node_avlt *node)
{
	if (node == NULL)
		return (0);
	return (get_height(node->left) - get_height(node->right));
}

static void	ft_balance_tree(t_node_avlt **p_root, \
	int (*cmp)(t_node_avlt *, t_node_avlt *))
{
	int balance;

	balance = get_balance(*p_root);
	if (balance < -1)
	{
		if (cmp((*p_root), (*p_root)->right) < 0)
			(*p_root)->right = ft_avlt_right_rot((*p_root)->right);
		*p_root = (ft_avlt_left_rot((*p_root)));
	}
	if (balance > 1)
	{
		if (cmp((*p_root), (*p_root)->left) >= 0)
			(*p_root)->left = ft_avlt_left_rot((*p_root)->left);
		*p_root = (ft_avlt_right_rot((*p_root)));
	}
}

t_node_avlt	*ft_avlt_insert(t_node_avlt **p_root, t_node_avlt *node, \
	int (*cmp)(t_node_avlt *, t_node_avlt *))
{
	int balance;

	if (p_root == NULL || *p_root == NULL || node == NULL)
		return (NULL);
	if (cmp(*p_root, node) < 0)
	{
		if ((*p_root)->right == NULL)
			(*p_root)->right = node;
		else
			node = ft_avlt_insert(&((*p_root)->right), node, cmp);
	}
	else
	{
		if ((*p_root)->left == NULL)
			(*p_root)->left = node;
		else
			node = ft_avlt_insert(&((*p_root)->left), node, cmp);
	}
	(*p_root)->height = 1 + \
		max(get_height((*p_root)->right), get_height((*p_root)->left));
	ft_balance_tree(p_root, cmp);
	return (node);
}
