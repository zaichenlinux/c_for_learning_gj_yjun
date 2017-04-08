#include <stdlib.h>
#include <assert.h>
#include "queue.h"

static void push(QUEUE *queue, elem_t data)
{
	QNODE *node = malloc(sizeof(QNODE));
	assert(node);
	node->data = data;
	INIT_LIST_HEAD(&node->list);

	list_add_tail(&node->list, &queue->head);
}

static elem_t pop(QUEUE *queue)
{
	QNODE *save = NULL; 
	if (!queue->is_empty(queue)) {
		save = container_of(queue->head.next, QNODE, list);
		
		elem_t save_data = save->data;

		list_del(queue->head.next);

		free(save);

		return save_data;
	}

	return NULL;
}

static elem_t top(QUEUE *queue)
{
	if (!queue->is_empty(queue)) {
		return container_of(queue->head.next, QNODE, list)->data;
	}

	return NULL;
}

static int queue_is_empty(QUEUE *queue)
{
	return list_is_empty(&queue->head);
}

void init_queue(QUEUE *queue)
{
	INIT_LIST_HEAD(&queue->head);

	queue->push = push;
	queue->pop = pop;
	queue->top = top;
	queue->is_empty = queue_is_empty;
}

void destroy_queue(QUEUE *queue)
{
	while (!queue->is_empty(queue)) {
		queue->pop(queue);
	}
}
