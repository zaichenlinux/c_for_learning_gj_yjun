#pragma once

// 双向有头循环链表

typedef struct node {
	int data;
	struct node *prev; // 指向前一个节点的指针
	struct node *next; // 指向后一个节点的指针
} NODE;

typedef struct list {
	NODE *head;

	void (*node_init)(NODE *); // 初始化某个节点的

	void (*add)(struct list *, NODE *);
	void (*add_tail)(struct list *, NODE *);
	NODE *(*search)(struct list *, int);
	void (*del)(NODE *);
	void (*for_each)(struct list *);

	void (*destroy)(struct list *);

} list;

void init_list(list *);
