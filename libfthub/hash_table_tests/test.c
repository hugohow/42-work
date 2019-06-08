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
	hash_table = ft_ht_create();
	printf("\033[32mCheck if created \033[00m\n");
	assert(hash_table != NULL);
	printf("-------------Test ft_ht_add-------------\n");
	ft_ht_add(hash_table, "firsta", (void *)&a);
	ft_ht_add(hash_table, "firstb", (void *)&b);
	printf("-------------Test ft_ht_get-------------\n");
	printf("\033[32mCheck firsta element exists \033[00m\n");
	assert(ft_ht_get(hash_table, "firsta") != NULL);
	printf("\033[32mCheck firsta element is correct\033[00m\n");
	assert(*((int *)(ft_ht_get(hash_table, "firsta")->datum)) == a);
	printf("\033[32mCheck firstb element exists \033[00m\n");
	assert(ft_ht_get(hash_table, "firstb") != NULL);
	printf("\033[32mCheck firstb element is correct\033[00m\n");
	assert(*((int *)(ft_ht_get(hash_table, "firstb")->datum)) == b);
	printf("\033[32mCheck xx element doesnt exist\033[00m\n");
	assert(ft_ht_get(hash_table, "xx") == NULL);


	printf("-------------Test ft_ht_free-------------\n");
	ft_ht_free(&hash_table);
	return (0);
}
