#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "queue.h"

static inline void push(struct queue *queue, qelem_t data)
{
	struct queue_node *snode = (struct queue_node *)malloc(sizeof(struct queue_node));
	assert(snode);
	snode->data = data;
	INIT_LIST_HEAD(&snode->list);
	list_add_tail(&snode->list, &queue->head);
}

static inline qelem_t pop(struct queue *queue)
{
	if (queue->is_empty(queue)) {
		exit (1);
	}

	struct queue_node *snode = container_of(queue->head.next, struct queue_node, list);
	qelem_t save = snode->data;

	list_del(queue->head.next);
	free(snode);

	return save;
}

static inline qelem_t top(struct queue *queue)
{
	if (queue->is_empty(queue)) {
		exit (1);
	}

	qelem_t save = container_of(queue->head.next, struct queue_node, list)->data;

	return save;
}

static inline int queue_is_empty(struct queue *queue)
{
	return list_is_empty(&queue->head);
}

void queue_init(struct queue *queue)
{
	INIT_LIST_HEAD(&queue->head);

	queue->is_empty = queue_is_empty;
	queue->push = push;
	queue->pop = pop;
	queue->top = top;
}

void queue_destroy(struct queue *queue)
{
	struct queue_node *snode = NULL;
	list_for_each_entry(snode, &queue->head, list) {
		queue->pop(queue);
	}
}
