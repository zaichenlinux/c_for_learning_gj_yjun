#pragma once
#include "list.h"

typedef struct sort {
	
	void (*swap)(list_head *, list_head *); // 交换链表上的两个节点
	void (*bubble)(list_head *, int (*)(list_head *, list_head *));
	void (*select)(list_head *, int (*)(list_head *, list_head *));
	void (*insert)(list_head *, int (*)(list_head *, list_head *));

} SORT;

void init_sort(SORT *);
