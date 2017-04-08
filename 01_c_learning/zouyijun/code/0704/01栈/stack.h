#pragma once
#include "list.h"

// 栈的操作：入栈，出栈，访问栈顶节点，判断栈是否为空

// 定义插入到栈中的节点的类型
typedef struct stack_node 
{
	int data;
	struct list_head list;
} SNODE;

// 定义栈的类型
typedef struct stack {
	struct list_head head; // 栈顶的头节点

	void (*push)(struct stack *, SNODE *); // 入栈
	SNODE *(*pop)(struct stack *); // 节点在出栈之前，保存下节点的地址
	SNODE *(*top)(struct stack *); // 访问栈顶节点
	int (*is_empty)(struct stack *); // 判断栈是否为空
} STACK;

void init_stack(STACK *);
void destroy_stack(STACK *);
