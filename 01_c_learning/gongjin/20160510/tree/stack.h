#pragma once
#include "list.h"

//typedef int selem_t;
typedef struct btree_node * selem_t;
struct stack_node {
	selem_t data;
	struct list_head list;
};

struct stack {
	struct list_head head; //栈顶头节点

	void (*push)(struct stack *, selem_t); //入栈
	selem_t (*pop)(struct stack *); //出栈
	selem_t (*top)(struct stack *); //访问栈顶节点
	int (*is_empty)(struct stack *); //判空
};

void stack_init(struct stack *);
void stack_destroy(struct stack *);
