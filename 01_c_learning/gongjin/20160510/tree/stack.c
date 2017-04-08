#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"

static inline void push(struct stack *stack, selem_t data)
{
	struct stack_node *snode = (struct stack_node *)malloc(sizeof(struct stack_node));
	assert(snode);
	snode->data = data;
	INIT_LIST_HEAD(&snode->list);
	list_add(&snode->list, &stack->head);
}

static inline selem_t pop(struct stack *stack)
{
	if (stack->is_empty(stack)) {
		exit (1);
	}

	struct stack_node *snode = container_of(stack->head.next, struct stack_node, list);
	selem_t save = snode->data;

	list_del(stack->head.next);
	free(snode);

	return save;
}

static inline selem_t top(struct stack *stack)
{
	if (stack->is_empty(stack)) {
		exit (1);
	}

	selem_t save = container_of(stack->head.next, struct stack_node, list)->data;

	return save;
}

static inline int stack_is_empty(struct stack *stack)
{
	return list_is_empty(&stack->head);
}

void stack_init(struct stack *stack)
{
	INIT_LIST_HEAD(&stack->head);

	stack->is_empty = stack_is_empty;
	stack->push = push;
	stack->pop = pop;
	stack->top = top;
}

void stack_destroy(struct stack *stack)
{
	struct stack_node *snode = NULL;
	list_for_each_entry(snode, &stack->head, list) {
		stack->pop(stack);
	}
}
