#include <stdlib.h>
#include <assert.h>
#include "stack.h"

static int stack_empty(list_head *stack)
{
	return list_is_empty(stack);
}

static void push(list_head *node, list_head *stack)
{
	list_add(node, stack);
}

static list_head *pop(list_head *stack)
{
	if (!stack_empty(stack)) {
		// 保存要弹出栈的节点
		list_head *save = stack->next;
		// 弹出节点
		list_del(save);
		return save;
	}

	return NULL;
}

static list_head *top(list_head *stack)
{
	if (!stack_empty(stack)) {
		return stack->next;
	}

	return NULL;
}


void init_stack(STACK *stack)
{
	stack->head = malloc(sizeof(list_head));

	assert(stack->head);
	INIT_LIST_HEAD(stack->head);
	stack->push = push;
	stack->pop = pop;
	stack->top = top;
	stack->is_empty = stack_empty;
}

void destroy_stack(STACK *stack)
{
	free(stack->head);
	free(stack);
}
