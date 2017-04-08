#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static void node_init(NODE *node)
{
	node->prev = node;
	node->next = node;
}

// 将node指向的节点，插入到prev_node指向的节点 和 next_node指向的节点之间
static void __add(NODE *node, NODE *prev_node, 
		NODE *next_node)
{
	prev_node->next = node;
	next_node->prev = node;
	node->next = next_node;
	node->prev = prev_node;
}

// 插入到链表头节点的后面
static void list_add_after_head(list *dlist, NODE *node)
{
	__add(node, dlist->head, dlist->head->next);
}

// 插入到链表头节点的前面
static void list_add_before_head(list *dlist, NODE *node)
{
	__add(node, dlist->head->prev, dlist->head);
}

static void list_for_each(list *dlist)
{
	NODE *cur = dlist->head->next;
	for (; cur != dlist->head; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}

static NODE *search(list *dlist, int data)
{
	NODE *cur = dlist->head->next;
	for (; cur != dlist->head; cur = cur->next) {
		if (cur->data == data) {
			return cur;
		}
	}
	return NULL;
}

static void list_del(NODE *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;

	node_init(node); // 初始化node节点本身，使其不再指向之前它所在链表的前后两个节点
}

// 判断一个链表是否为空
static int __is_empty(list *dlist)
{
	return dlist->head->next == dlist->head; //空返回1
}

static void destroy_list(list *dlist)
{
	while (!__is_empty(dlist)) {
		dlist->del(dlist->head->next);
	}
	free(dlist->head);
}	

void init_list(list *dlist)
{
	dlist->head = malloc(sizeof(NODE));
	if (!(dlist->head)) {
		printf("申请头节点的堆空间失败！\n");
		return;
	}

	dlist->head->data = 0; // 初始化头节点的数据域
	node_init(dlist->head); // 初始化头节点的指针域

	dlist->node_init = node_init; 
	dlist->add = list_add_before_head;
	dlist->add_tail = list_add_after_head;
	dlist->for_each = list_for_each;
	dlist->search = search;
	dlist->del = list_del;
	dlist->destroy = destroy_list;
}
