#pragma once

typedef struct list_head {
	struct list_head *prev;
	struct list_head *next;
} list_head;

#define list_head(head) \
	list_head head = {&head, &head}

static void INIT_LIST_HEAD(list_head *head)
{
	head->prev = head;
	head->next = head;
}

static void __add(list_head *list, list_head *prev, list_head *next)
{
	list->prev = prev;
	list->next = next;
	prev->next = list;
	next->prev = list;
}

static void list_add(list_head *list, list_head *head) 
{
	__add(list, head, head->next);
}

static void list_add_tail(list_head *list, list_head *head) 
{
	__add(list, head->prev, head);
}

static void list_del(list_head *list)
{
	list->prev->next = list->next;
	list->next->prev = list->prev;
}

static void list_del_init(list_head *list)
{
	list->prev->next = list->next;
	list->next->prev = list->prev;

	INIT_LIST_HEAD(list);
}

static int list_is_empty(list_head *head) 
{
	return head->next == head; // 为空返回1
}

// macro
#define offsetof(type, member) \
	((size_t)(&((type *)0)->member))

#define container_of(ptr, type, member) \
	((type*)((size_t)(ptr) - offsetof(type, member)))

#define list_for_each(cur, head) \
   for (cur = (head)->next; cur != (head); cur = (cur)->next)	

#define list_for_each_safe(cur, tmp, head) \
	for (cur = (head)->next, tmp = (cur)->next; \
			cur != (head); \
			cur = tmp, tmp = (tmp)->next)

#define list_for_each_entry(ptr, head, member) \
	for (ptr = container_of((head)->next, typeof(*(ptr)), member); \
		&(ptr)->member != (head); \
		ptr = container_of((ptr)->member.next, typeof(*(ptr)), member))

#define list_for_each_entry_safe(ptr, tmp, head, member) \
	for (ptr = container_of((head)->next, typeof(*ptr), member), \
		tmp = (ptr)->member.next; \
		&(ptr)->member != (head); \
		ptr = container_of(tmp, typeof(*(ptr)), member), \
			tmp = (tmp)->next)


