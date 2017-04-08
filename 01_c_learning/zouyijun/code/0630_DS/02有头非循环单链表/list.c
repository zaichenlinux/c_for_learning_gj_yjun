#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void list_add(list *slist, int data)
{
	NODE *node = malloc(sizeof(NODE));
	if (!node) {
		printf("申请要加入到链表上的节点的空间失败！\n");
		return;
	}
	node->data = data;
	node->next = NULL;

	// 将上面准备好的节点插入到链表
	node->next = slist->head->next;
	slist->head->next = node;
}

static void list_add_tail(list *slist, int data)
{
	NODE *node = malloc(sizeof(NODE));
	if (!node) {
		printf("申请要加入到链表上的节点的空间失败！\n");
		return;
	}
	node->data = data;
	node->next = NULL;

	NODE *cur = slist->head;
	for (; cur->next; cur = cur->next) {}
	// 插入到链表
	cur->next = node;
}

static NODE *search_node(list *slist, int data)
{
	NODE *cur = slist->head;
	for (; cur; cur = cur->next) {
		if (cur->data == data) {
			return cur;
		}
	}
	return NULL;
}

static void list_for_each(list *slist, void (*todo)(NODE *))
{
	NODE *cur = slist->head->next;
	for (; cur; cur = cur->next) {
		todo(cur);
	}
}

static void list_del(list *slist, int data)
{
	NODE *tmp = slist->head;
	NODE *cur = slist->head->next;
	for (; cur; cur = tmp->next) {
		if (cur->data == data) {
			tmp->next = cur->next;
			free(cur);
		} else {
			tmp = cur;
		}
	}
}

void init_list(list *slist)
{
	// 申请头节点的空间
	slist->head = malloc(sizeof(NODE));
	if (!(slist->head)) {
		printf("申请头节点的空间失败！\n");
		return;
	}
	// 初始化头节点
	slist->head->data = 0;
	slist->head->next = NULL;

	slist->add = list_add;
	slist->add_tail = list_add_tail;
	slist->list_for = list_for_each;
	slist->search = search_node;
	slist->del = list_del;
}

void destroy_list(list *slist)
{
	while (slist->head->next) { //如果链表非空
		slist->del(slist, slist->head->next->data);
	}
	free(slist->head); // 释放头节点占据的空间
	free(slist); // 释放链表对象的空间
}
