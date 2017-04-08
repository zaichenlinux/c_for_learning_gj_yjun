#pragma once

// 有头的非循环单链表

typedef struct node {
	int data;
	struct node *next;
} NODE;

typedef struct list {
	
	NODE *head; // 头指针

	void (*add)(struct list *, int); // 头插
	void (*add_tail)(struct list *, int); // 尾插

	void (*list_for)(struct list *, void (*)(NODE *)); // 遍历

	void (*del)(struct list *, int); // 删除

	NODE *(*search)(struct list *, int); // 查找

} list;

void init_list(list *); // 初始化链表对象（C++中的构造函数）
void destroy_list(list *); // 销毁链表对象（C++中的析构函数）
