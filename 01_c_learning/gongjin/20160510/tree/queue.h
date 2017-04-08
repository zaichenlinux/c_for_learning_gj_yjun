#pragma once
#include "list.h"

//typedef int qelem_t;
typedef struct btree_node * qelem_t;
struct queue_node {
	qelem_t data;
	struct list_head list;
};

struct queue {
	struct list_head head; //队头头节点

	void (*push)(struct queue *, qelem_t); //入队
	qelem_t (*pop)(struct queue *); //出队
	qelem_t (*top)(struct queue *); //访问队头节点
	int (*is_empty)(struct queue *); //判空
};

void queue_init(struct queue *);
void queue_destroy(struct queue *);
