#pragma once
#include "list.h"
#include "btree.h"

typedef BTNODE *elem_t;
//typedef int elem_t;

typedef struct stack_node {
	elem_t data;
	struct list_head list;
} SNODE;

typedef struct stack {
	list_head head;

	void (*push)(struct stack *, elem_t); // 入栈
	elem_t (*pop)(struct stack *); // 出栈
	elem_t (*top)(struct stack *); // 访问栈顶节点
	int (*is_empty)(struct stack *); // 栈是否为空

} STACK;	

void init_stack(STACK *);
void destroy_stack(STACK *);
