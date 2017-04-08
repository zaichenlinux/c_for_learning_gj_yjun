#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct queue_node {
	int data;
	struct list_head list;
} QNODE;

int main()
{
	QUEUE *q = malloc(sizeof(QUEUE));
	assert(q);
	init_queue(q);

#define CNT 10
	QNODE *node = NULL;
	for (int i = 0; i < CNT; i++) {
		node = malloc(sizeof(QNODE));
		assert(node);

		node->data = i;
		INIT_LIST_HEAD(&node->list);

		q->push(&node->list, q);
	}

	printf("队头节点值：%d\n", 
			container_of(q->top(q), QNODE, list)->data);

#if 1
	printf("出队: ");
	while (!(q->is_empty(q))) {
		QNODE *qn = container_of(q->pop(q), QNODE, list);
		printf("%d ", qn->data);
		free(qn);
	}
	printf("\n");
#endif

	destroy_queue(q);

	return 0;
}
