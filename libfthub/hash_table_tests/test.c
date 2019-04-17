#include "ht.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
	t_ht *hash_table;
	int a;
	int b;

	a = 10;
	b = 20;
	printf("-------------Test ft_ht_create-------------\n");
	hash_table = ft_ht_create(9999);
	printf("\033[32mCheck size \033[00m\n");
	assert(hash_table->size == 9999);
	printf("\033[32mCheck table \033[00m\n");
	assert(hash_table->table != 0x0);
	printf("\033[32mCheck first element of the table \033[00m\n");
	assert(hash_table->table[0] == 0x0);
	printf("-------------Test ft_ht_add-------------\n");
	ft_ht_add(hash_table, "first", (void *)&a);
	printf("Add one element\n");
	assert(hash_table->size == 9999);
	assert(hash_table->table != 0x0);
	assert(hash_table->table[0] != 0x0);
	printf("\033[32mCheck data first element of the table \033[00m\n");
	assert(*(int *)(hash_table->table[0]->datum) == a);
	printf("\033[32mCheck node length \033[00m\n");
	assert(hash_table->table[0]->next == 0x0);
	printf("\033[32mCheck table length \033[00m\n");
	assert(hash_table->table[1] == 0x0);
	printf("Add second element\n");
	ft_ht_add(hash_table, "second", (void *)&b);
	assert(hash_table->size == 9999);
	assert(hash_table->table != 0x0);
	assert(hash_table->table[0] != 0x0);
	assert(*(int *)(hash_table->table[0]->datum) == a);
	assert(hash_table->table[0]->next == 0x0);
	printf("\033[32mCheck if node has been added \033[00m\n");
	assert(hash_table->table[1] != 0x0);
	printf("\033[32mCheck its data \033[00m\n");
	assert(*((int *)(hash_table->table[1]->datum)) == b);
	printf("\033[32mCheck its next \033[00m\n");
	assert(hash_table->table[1]->next == 0);
	printf("\033[32mCheck table len \033[00m\n");
	assert(hash_table->table[2] == 0);
	printf("Add element to first\n");
	ft_ht_add(hash_table, "first", (void *)&b);

	assert(hash_table->size == 9999);
	assert(hash_table->table != 0x0);
	assert(hash_table->table[0] != 0x0);
	assert(*(int *)(hash_table->table[0]->datum) == a);
	assert(hash_table->table[1] != 0x0);
	assert(*((int *)(hash_table->table[1]->datum)) == b);
	assert(hash_table->table[1]->next == 0);
	assert(hash_table->table[2] == 0);

	printf("\033[32mCheck if node has been added \033[00m\n");
	assert(hash_table->table[0]->next != 0x0);
	printf("\033[32mCheck its data \033[00m\n");
	assert(*((int *)(((hash_table->table[0])->next)->datum)) == b);
	printf("\033[32mCheck if the len is ok \033[00m\n");
	assert(((hash_table->table[0])->next)->next == 0x0);
	printf("-------------Test ft_ht_get-------------\n");
	t_node_ht *node;
	node = ft_ht_get(hash_table, "first");
	printf("\033[32mFirst get\033[00m\n");
	assert(*((int *)node->datum) == a);
	node = ft_ht_get(hash_table, "second");
	printf("\033[32mSecond get\033[00m\n");
	assert(*((int *)node->datum) == b);
	node = ft_ht_get(hash_table, "third");
	printf("\033[32munknown key\033[00m\n");
	assert(node == 0x0);
	printf("-------------Test ft_ht_free-------------\n");
	ft_ht_free(&hash_table);
	printf("\033[32mcheck hash_table NULL\033[00m\n");
	assert(hash_table == 0x0);
	return (0);
}
