#pragma once

struct list_head {
	struct list_head *prev;
	struct list_head *next;
};

#define LIST_HEAD(head) \
	struct list_head head = {&head, &head}

static inline void INIT_LIST_HEAD(struct list_head *head)
{
	head->prev = head;
	head->next = head;
}

static inline void __add(struct list_head *list, struct list_head *prev, struct list_head *next)
{
	list->prev = prev;
	list->next = next;
	prev->next = list;
	next->prev = list;
}

static inline void list_add(struct list_head *list, struct list_head *head)
{
	__add(list, head, head->next);
}

static inline void list_add_tail(struct list_head *list, struct list_head *head)
{
	__add(list, head->prev, head);
}

static inline struct list_head *search(struct list_head *list, struct list_head *head)
{
	struct list_head *cur = head->next;
	for (; cur != list; cur = cur->next) {
		if (cur == head) {
			return NULL;
		}
	}
	return cur;
}

static inline void list_del(struct list_head *list)
{
	list->prev->next = list->next;
	list->next->prev = list->prev;

	INIT_LIST_HEAD(list);
}

static inline int list_is_empty(struct list_head *head)
{
	return head->next == head;
}

//macro
#define offsetof(type, member) \
	((size_t)(&((type *)0)->member))

#define container_of(ptr, type, member) \
	hlist_entry(ptr, type, member)

#define hlist_entry(ptr, type, member) \
	((type *)((size_t)(ptr) - offsetof(type, member)))

#define hlist_for_each(cur, head) \
	for (cur = (head)->next; \
			cur != head; \
			cur = (cur)->next)

#define hlist_for_each_safe(cur, tmp, head) \
	for (cur = (head)->next, \
			tmp = (cur)->next; \
			cur != head; \
			cur = tmp, tmp = (tmp)->next)

#define hlist_for_each_entry(ptr, head, member) \
	for (ptr = hlist_entry((head)->next, typeof(*ptr), member); \
		&(ptr)->member != head; \
		ptr = hlist_entry((ptr)->member.next, typeof(*ptr), member)) 

#define hlist_for_each_entry_safe(ptr, tmp, head, member) \
	for (ptr = hlist_entry((head)->next, typeof(*ptr), member), tmp = (ptr)->member.next; \
		&(ptr)->member != head; \
		ptr = hlist_entry(tmp, typeof(*ptr), member), tmp = (tmp)->next)
