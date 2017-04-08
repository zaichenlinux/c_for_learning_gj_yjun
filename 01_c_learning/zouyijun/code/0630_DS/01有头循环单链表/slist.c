#include <stdio.h>
#include "slist.h"

static void insert_head(list *slist, NODE *node)
{
	node->next = slist->head.next;
	slist->head.next = node;
}

static void insert_tail(list *slist, NODE *node)
{
	NODE *cur = &slist->head;
	// 先找到链表上的最后一个节点
	for (; cur->next != &slist->head; cur = cur->next) {}
	
	// 将node指针指向的节点插入到cur指向的节点和cur指向的节点之后的那个节点之间
	cur->next = node;
	node->next = &slist->head;
}

static void list_for_each(list *slist)
{
	NODE *cur = slist->head.next;
	for (; cur != &slist->head; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}

static void delete_node(list *slist, NODE *node)
{
	NODE *cur = &slist->head;

	for (; cur->next != node; cur = cur->next) {
		// 没有找到这个节点
		if (cur->next == &slist->head) { // cur当前指向的节点的下一个节点已经是头节点，那么说明没有找到
			printf("要删除的节点不存在!\n");
			return;
		}
	}

	// 找到了要删除的节点
	cur->next = node->next; // 删除node指针指向的节点
	node->next = node; // 让node指针指向的节点的next指针不再指向它在删除之前所指向的那个节点，而变成指向它自己
}

static NODE *search_node(list *slist, NODE *node)
{
	NODE *cur = slist->head.next;
	for (; cur != &slist->head; cur = cur->next) {
		if (cur == node) {
			return node;
		}
	}

	printf("没找到!\n");
	return NULL; // 没找到
}

static void destroy_list(list *slist)
{
	while (slist->head.next != &slist->head) {
		delete_node(slist, slist->head.next);
	}
}

void init_list(list *slist)
{
	// 初始化头节点
	slist->head.data = 99;
	slist->head.next = &slist->head;

	// 初始化函数指针
	slist->insert_head = insert_head;
	slist->insert_tail = insert_tail;
	slist->list_for_each = list_for_each;

	slist->del = delete_node;
	slist->search = search_node;
	slist->destroy = destroy_list;
}
