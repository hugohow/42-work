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
	int e;
	int f;

	a = 10;
	b = 20;
	c = 30;
	d = 40;
	e = 50;
	f = 25;

//    The constructed AVL Tree would be 
//             30 
//            
//          20   40 
//         
//        10  25    50 
//  
  


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
	node = ft_avlt_add(&root, (void *)(&c), sizeof(int), &cmp);
	node = ft_avlt_add(&root, (void *)(&d), sizeof(int), &cmp);
	node = ft_avlt_add(&root, (void *)(&e), sizeof(int), &cmp);
	node = ft_avlt_add(&root, (void *)(&f), sizeof(int), &cmp);
	printf("\033[32mCheck if root content is 30 \033[00m\n");
	assert(*((int *)(root->content)) == c);
	printf("\033[32mCheck if root->left content is 20 \033[00m\n");
	assert(*((int *)((root->left)->content)) == b);
	printf("\033[32mCheck if root->right content is 40 \033[00m\n");
	assert(*((int *)((root->right)->content)) == d);
	printf("\033[32mCheck if root->right->right content is 50 \033[00m\n");
	assert(*((int *)(((root->right)->right)->content)) == e);
	printf("\033[32mCheck if root->left->right content is 25 \033[00m\n");
	assert(*((int *)(((root->left)->right)->content)) == f);
	printf("\033[32mCheck if root->left->left content is 10 \033[00m\n");
	assert(*((int *)(((root->left)->left)->content)) == a);
	printf("\033[32mCheck if root->left->left->left is NULL \033[00m\n");
	assert((((root->left)->left)->left) == NULL);
	printf("\033[32mCheck if root->left->left->right is NULL \033[00m\n");
	assert((((root->left)->left)->right) == NULL);
	printf("\033[32mCheck if root->left->left->left is NULL \033[00m\n");
	assert((((root->left)->right)->left) == NULL);
	printf("\033[32mCheck if root->left->left->right is NULL \033[00m\n");
	assert((((root->left)->right)->right) == NULL);
	printf("\033[32mCheck if root->left->left->left is NULL \033[00m\n");
	assert((((root->right)->right)->left) == NULL);
	printf("\033[32mCheck if root->left->left->right is NULL \033[00m\n");
	assert((((root->right)->right)->right) == NULL);
	printf("\033[32mCheck if root->left->left->left is NULL \033[00m\n");
	assert((root->right)->left == NULL);
	printf("\033[32mCheck if root->left->left->right is NULL \033[00m\n");
	assert((root->right)->left == NULL);
	ft_avlt_free(&root);
	return (0);
}
