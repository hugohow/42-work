#include "avltree.h"
#include <stdio.h>
#include <assert.h>

int cmp(t_node_avlt *node1, t_node_avlt *node2)
{
	return (*((int *)(node1->content)) - *((int *)(node2->content)));
}

int main(void)
{
	t_node_avlt *root;
	t_node_avlt *node;
	int a;
	int b;
	int c;
	int d;

	a = 10;
	b = 20;
	c = 15;
	d = 1;
	printf("-------------Test ft_avlt_create-------------\n");
	root = ft_avlt_create((void *)(&a), sizeof(int));
	printf("\033[32mCheck if avl tree if created and had the good value \033[00m\n");
	assert(root != NULL);
	assert(root->content != NULL);
	assert(*((int *)(root->content)) == a);
	assert(root->left == NULL);
	assert(root->right == NULL);
	printf("-------------Test ft_avlt_add && ft_apply_inorder && ft_avlt_insert-------------\n");
	node = ft_avlt_add(&root, (void *)(&b), sizeof(int), &cmp);
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

	// node = ft_avlt_add(&root, (void *)(&c), sizeof(int), &cmp);
	// printf("\033[32mCheck if node2 is created \033[00m\n");
	// assert(node != NULL);
	// assert(node->content != NULL);
	// assert(*((int *)(node->content)) == c);
	// assert(node->left == NULL);
	// assert(node->right == NULL);
	// printf("\033[32mCheck if the node2 is in the right place \033[00m\n");
	// assert(root->right != NULL);
	// assert(root->left == NULL);
	// assert((root->right)->left == node);
	// assert((root->right)->right == NULL);


	// node = ft_avlt_add(&root, (void *)(&d), sizeof(int), &cmp);
	// printf("\033[32mCheck if node3 is created \033[00m\n");
	// assert(node != NULL);
	// assert(node->content != NULL);
	// assert(*((int *)(node->content)) == d);
	// assert(node->left == NULL);
	// assert(node->right == NULL);
	// printf("\033[32mCheck if the node3 is in the right place \033[00m\n");
	// assert(root->right != NULL);
	// assert(root->left != NULL);
	// assert(root->left == node);

	// printf("-------------Test ft_avlt_free-------------\n");
	// ft_avlt_free(&root);
	// printf("\033[32mCheck if root and node had been freed \033[00m\n");
	// assert(root == NULL);
	return (0);
}
