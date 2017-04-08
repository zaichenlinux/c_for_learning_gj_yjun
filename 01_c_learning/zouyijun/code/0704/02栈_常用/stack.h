#pragma once
#include "list.h"

// 栈的特点：先进后出 FILO(first int last out)
// 栈的操作：入栈（插入节点到栈顶），出栈（从栈顶删除节点），访问栈顶节点，判断栈是否为空

typedef struct stack {
	list_head *head; // 指向头节点的指针

	// 将第一个参数表示的节点，插入到第二个参数所表示的那个栈中
	void (*push)(list_head *, list_head *); // 入栈
	list_head *(*pop)(list_head *);// 出栈
	list_head *(*top)(list_head *); // 访问栈顶
	int (*is_empty)(list_head *); // 判断栈空否
} STACK;

/*
typedef struct stack {
	list_head *head; // 指向头节点的指针

	void (*push)(struct stack *, list_head *); // 入栈
	list_head *(*pop)(struct stack *);// 出栈
	list_head *(*top)(struct stack *); // 访问栈顶
	int (*is_empty)(struct stack *); // 判断栈空否
} STACK;
*/

void init_stack(STACK *);
void destroy_stack(STACK *);
