#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct stack_node {
	int data;
	struct list_head list;
} SNODE;

int main()
{
	STACK *s = malloc(sizeof(STACK));
	assert(s);
	init_stack(s);

#define CNT 10
	SNODE *node = NULL;
	for (int i = 0; i < CNT; i++) {
		node = malloc(sizeof(SNODE));
		assert(node);

		node->data = i;
		INIT_LIST_HEAD(&node->list);

		s->push(&node->list, s->head);
	}

	printf("栈顶节点值：%d\n", 
			container_of(s->top(s->head), SNODE, list)->data);

#if 1
	printf("出栈: ");
	while (!(s->is_empty(s->head))) {
		SNODE *sn = container_of(s->pop(s->head), SNODE, list);
		printf("%d ", sn->data);
		free(sn);
	}
	printf("\n");
#endif

	destroy_stack(s);

	return 0;
}
