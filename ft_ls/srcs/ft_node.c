#include "ft_ls.h"

t_btree		*btree_create_node(void *item)
{
	t_btree		*node;

	if (!(node = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	if (node)
	{
		node->left = 0;
		node->right = 0;
		node->content = item;
	}
	return (node);
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	node = *root;
	if ((*cmpf)(item, node->content) < 0)
	{
		if (node->left)
			btree_insert_data(&node->left, item, cmpf);
		else
			node->left = btree_create_node(item);
	}
	else
	{
		if (node->right)
			btree_insert_data(&node->right, item, cmpf);
		else
			node->right = btree_create_node(item);
	}
}

void ft_traverse_tree(t_btree *root, void (*f)(t_btree *))
{
    if (root == NULL)
        return ;
    if (root->left)
        ft_traverse_tree(root->left, f);
    f(root);
    if (root->right)
        ft_traverse_tree(root->right, f);
}