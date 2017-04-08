#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* 创建一个链表节点，包含用户数据区
 * @list: 指向链表主对象的指针
 * @size: 节点中用户数据的大小
 */
static struct list_node *alloc_node(struct list_info *list, size_t size)
{
	struct list_node *node = malloc(size + sizeof(struct list_node));
	if (!node) {
		fprintf(stderr, "alloc node failed\n");
		return NULL;
	}

	node->prev = node;
	node->next = node;

	return node;
}

/* @插入一个新的节点到链表中
 * @new_node: 将要插入到链表的新节点
 * @prev_node, next_node: 新节点插入到这两个相邻节点的中间
 */
static void __list_add(struct list_info *list,
		struct list_node *new_node, struct list_node *prev_node, struct list_node *next_node)
{
	new_node->prev = prev_node;
	new_node->next = next_node;
	prev_node->next = new_node;
	next_node->prev = new_node;
}

//头插法
static void list_add(struct list_info *list,
		struct list_node *new_node)
{
	__list_add(list, new_node, &list->head, list->head.next);
}

//尾插法
static void list_add_tail(struct list_info *list,
		struct list_node *new_node)
{
	__list_add(list, new_node, list->head.prev, &list->head);
}

static void list_del_node(struct list_info *list,
		struct list_node *dst_node)
{
	dst_node->prev->next = dst_node->next;
	dst_node->next->prev = dst_node->prev;
	dst_node->prev = dst_node;
	dst_node->next = dst_node;

	free(dst_node);
}

/* 正向遍历链表，由用户提供的回调函数来依次操作每一个遍历到的节点
 * @func: 回调函数, 会依次操作每一个节点
 * @arg： 回调函数的参数
 */
static void *list_for_each(struct list_info *list,
		void *(*func)(struct list_info *list, struct list_node *, void *), void *arg)
{
	struct list_node *ptr = list->head.next;
	void *ret = NULL;

	for (; ptr != &list->head; ptr = ptr->next) {
		ret = func(list, ptr, arg);
		if (ret) {
			return ret;
		}
	}

	return ret;
}

/* 用于可能增减链表节点的操作的遍历函数 */
static void *list_for_each_safe(struct list_info *list,
		void *(*func)(struct list_info *list, struct list_node *, void *), void *arg)
{
	struct list_node *ptr = list->head.next;
	struct list_node *tmp = NULL;
	void *ret = NULL;

	for (; ptr != &list->head; ptr = tmp) {
		tmp = ptr->next;
		ret = func(list, ptr, arg);
		if (ret) {
			return ret;
		}
	}

	return ret;
}

int init_list(struct list_info *list)
{
	list->head.prev = &list->head;
	list->head.next = &list->head;

	list->alloc_node = alloc_node;
	list->__list_add = __list_add;
	list->list_add = list_add;
	list->list_add_tail = list_add_tail;
	list->list_del_node = list_del_node;
	list->list_for_each = list_for_each;
	list->list_for_each_safe = list_for_each_safe;
}