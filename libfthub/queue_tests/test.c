#include "queue.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
	t_queue *queue;
	int a;
	int b;

	a = 10;
	b = 20;
	printf("-------------Test ft_queue_init-------------\n");
	queue = ft_queue_init();
	printf("\033[32mCheck if stack is inited \033[00m\n");
	assert(queue != NULL);
	assert(queue->head == NULL);
	assert(queue->tail == NULL);
	assert(queue->size == 0);
	printf("-------------Test ft_queue_enqueue-------------\n");
	ft_queue_enqueue(&queue, (const void *)&a, sizeof(a));
	ft_queue_enqueue(&queue, (const void *)&b, sizeof(b));
	ft_queue_enqueue(&queue, (const void *)&a, sizeof(a));
	ft_queue_enqueue(&queue, (const void *)&b, sizeof(b));
	printf("\033[32mCheck if the value is is correct \033[00m\n");
	assert(queue != NULL);
	assert(queue->head != NULL);
	assert(queue->tail != NULL);
	assert(queue->size == 4);
	assert(*((int *)((queue->head)->content)) == a);
	printf("-------------Test ft_queue_dequeue-------------\n");
	ft_queue_dequeue(&queue);
	printf("\033[32mCheck if the value is correct for one dequeue \033[00m\n");
	assert(queue != NULL);
	assert(queue->head != NULL);
	assert(queue->tail != NULL);
	assert(queue->size == 3);
	assert(*((int *)((queue->head)->content)) == b);
	ft_queue_dequeue(&queue);
	printf("\033[32mCheck if the value is correct for two dequeue \033[00m\n");
	assert(queue != NULL);
	assert(queue->head != NULL);
	assert(queue->tail != NULL);
	assert(queue->size == 2);
	assert(*((int *)((queue->head)->content)) == a);
	ft_queue_dequeue(&queue);
	printf("\033[32mCheck if the value is correct for three dequeue \033[00m\n");
	assert(queue != NULL);
	assert(queue->head != NULL);
	assert(queue->tail != NULL);
	assert(queue->size == 1);
	assert(*((int *)((queue->head)->content)) == b);
	ft_queue_dequeue(&queue);
	printf("\033[32mCheck if the value is correct for four dequeue \033[00m\n");
	assert(queue != NULL);
	assert(queue->head == NULL);
	assert(queue->tail == NULL);
	assert(queue->size == 0);
	return (0);
}
