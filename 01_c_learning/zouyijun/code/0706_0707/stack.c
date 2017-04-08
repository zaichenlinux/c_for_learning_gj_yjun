#include <stdlib.h>
#include <assert.h>
#include "stack.h"

static void push(STACK *stack, elem_t data)
{
	SNODE *node = malloc(sizeof(SNODE));
	assert(node);
	node->data = data;
	INIT_LIST_HEAD(&node->list);

	list_add(&node->list, &stack->head);
}

static elem_t pop(STACK *stack)
{
	SNODE *save = NULL; 
	if (!stack->is_empty(stack)) {
		save = container_of(stack->head.next, SNODE, list);

		list_del(stack->head.next);
		
		elem_t save_data = save->data;

		free(save);

		//return save->data;
		return save_data;
	}

	return NULL;
}

static elem_t top(STACK *stack)
{
	if (!stack->is_empty(stack)) {
		return container_of(stack->head.next, SNODE, list)->data;
	}

	return NULL;
}

static int stack_is_empty(STACK *stack)
{
	return list_is_empty(&stack->head);
}

void init_stack(STACK *stack)
{
	INIT_LIST_HEAD(&stack->head);

	stack->push = push;
	stack->pop = pop;
	stack->top = top;
	stack->is_empty = stack_is_empty;
}

void destroy_stack(STACK *stack)
{
	while (!stack->is_empty(stack)) {
		stack->pop(stack);
	}
}
