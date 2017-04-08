#pragma once
#include "list.h"
#include "btree.h"

//typedef int elem_t;
typedef BTNODE *elem_t;

typedef struct queue_node {
	elem_t data;
	struct list_head list;
} QNODE;

typedef struct queue {
	list_head head;

	void (*push)(struct queue *, elem_t); // 入队
	elem_t (*pop)(struct queue *); // 出队
	elem_t (*top)(struct queue *); // 访问队头节点
	int (*is_empty)(struct queue *); // 队列是否为空

} QUEUE;	

void init_queue(QUEUE *);
void destroy_queue(QUEUE *);
