#include <stdlib.h>
#include <assert.h>
#include "queue.h"

static int queue_empty(QUEUE *queue)
{
	return list_is_empty(queue->head);
}

static void push(list_head *node, QUEUE *queue)
{
	list_add_tail(node, queue->head);
}

static list_head *pop(QUEUE *queue)
{
	if (!queue_empty(queue)) {
		// 保存要弹出队列的节点
		list_head *save = queue->head->next;
		// 弹出节点
		list_del(save);
		return save;
	}

	return NULL;
}

static list_head *top(QUEUE *queue)
{
	if (!queue_empty(queue)) {
		return queue->head->next;
	}

	return NULL;
}


void init_queue(QUEUE *queue)
{
	queue->head = malloc(sizeof(QUEUE));
	assert(queue->head);
	INIT_LIST_HEAD(queue->head);

	queue->push = push;
	queue->pop = pop;
	queue->top = top;
	queue->is_empty = queue_empty;
}

void destroy_queue(QUEUE *queue)
{
	free(queue->head);
	free(queue);
}
