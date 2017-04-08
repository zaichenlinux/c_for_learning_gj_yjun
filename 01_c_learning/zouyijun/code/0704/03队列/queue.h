#pragma once
#include "list.h"

// 队列的特点：先进先出 FIFO（first int first out）
// 队列的操作：入队（插入节点到队尾），出队（删除队头的节点），访问队头节点，判断队列是否为空

/*
typedef struct queue {
	list_head *head; // 指向头节点的指针

	// 将第一个参数表示的节点，插入到第二个参数所表示的那个队列中
	void (*push)(list_head *, list_head *); // 入队
	list_head *(*pop)(list_head *);// 出队
	list_head *(*top)(list_head *); // 访问队头
	int (*is_empty)(list_head *); // 判断队列空否
} QUEUE;
*/

typedef struct queue {
	list_head *head; // 指向头节点的指针

	void (*push)(list_head *, struct queue *); // 入队
	list_head *(*pop)(struct queue *);// 出队
	list_head *(*top)(struct queue *); // 访问队头
	int (*is_empty)(struct queue *); // 判断队列空否
} QUEUE;

void init_queue(QUEUE *);
void destroy_queue(QUEUE *);
