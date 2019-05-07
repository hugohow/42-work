#include "btree.h"
#include <stdio.h>
#include <assert.h>

int cmp(t_node_bt *node1, t_node_bt *node2)
{
	return (*((int *)(node1->content)) - *((int *)(node2->content)));
}

int main(void)
{
	t_node_bt *root;
	t_node_bt *node;
	int a;
	int b;
	int c;
	int d;

	a = 10;
	b = 20;
	c = 15;
	d = 1;
	printf("-------------Test ft_bt_create-------------\n");
	root = ft_bt_create((void *)(&a), sizeof(int));
	printf("\033[32mCheck if binary tree if created and had the good value \033[00m\n");
	assert(root != NULL);
	assert(root->content != NULL);
	assert(*((int *)(root->content)) == a);
	assert(root->left == NULL);
	assert(root->right == NULL);
	printf("-------------Test ft_bt_add && ft_apply_inorder && ft_bt_insert-------------\n");
	node = ft_bt_add(&root, (void *)(&b), sizeof(int), &cmp);
	printf("\033[32mCheck if node is created \033[00m\n");
	assert(node != NULL);
	assert(node->content != NULL);
	assert(*((int *)(node->content)) == b);
	assert(node->left == NULL);
	assert(node->right == NULL);
	printf("\033[32mCheck if the node is in the right place \033[00m\n");
	assert(root->right != NULL);
	assert(root->right == node);
	assert(root->left == NULL);

	node = ft_bt_add(&root, (void *)(&c), sizeof(int), &cmp);
	printf("\033[32mCheck if node2 is created \033[00m\n");
	assert(node != NULL);
	assert(node->content != NULL);
	assert(*((int *)(node->content)) == c);
	assert(node->left == NULL);
	assert(node->right == NULL);
	printf("\033[32mCheck if the node2 is in the right place \033[00m\n");
	assert(root->right != NULL);
	assert(root->left == NULL);
	assert((root->right)->left == node);
	assert((root->right)->right == NULL);


	node = ft_bt_add(&root, (void *)(&d), sizeof(int), &cmp);
	printf("\033[32mCheck if node3 is created \033[00m\n");
	assert(node != NULL);
	assert(node->content != NULL);
	assert(*((int *)(node->content)) == d);
	assert(node->left == NULL);
	assert(node->right == NULL);
	printf("\033[32mCheck if the node3 is in the right place \033[00m\n");
	assert(root->right != NULL);
	assert(root->left != NULL);
	assert(root->left == node);

	printf("-------------Test ft_bt_free-------------\n");
	ft_bt_free(&root);
	printf("\033[32mCheck if root and node had been freed \033[00m\n");
	assert(root == NULL);
	return (0);
}
