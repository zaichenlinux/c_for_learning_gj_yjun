#include <stdio.h>
#include "stack.h"

static int stack_is_empty(STACK *stack)
{
	return list_is_empty(&stack->head);
}

static void push(STACK *stack, SNODE *node)
{
	list_add(&node->list, &stack->head);
}

static SNODE *top(STACK *stack)
{
	if (!stack_is_empty(stack)) { // 栈不为空
		return container_of(stack->head.next, SNODE, list);
	}

	return NULL; // 栈为空，返回NULL
}

static SNODE *pop(STACK *stack)
{
	if (stack_is_empty(stack)) { // 栈为空
		return NULL;
	}

	SNODE *save_top = container_of(stack->head.next, SNODE, list);
	list_del_init(stack->head.next);

	return save_top;
}

void init_stack(STACK *stack)
{
	INIT_LIST_HEAD(&stack->head);

	stack->is_empty = stack_is_empty;
	stack->top = top;
	stack->pop = pop;
	stack->push = push;
}

void destroy_stack(STACK *stack)
{
	while (!stack_is_empty(stack)) {
		pop(stack);
	}
}
