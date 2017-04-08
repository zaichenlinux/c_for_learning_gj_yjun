#pragma once

// 表头节点的类型
typedef struct hlist_head {
	struct hlist_node *first;
} HLIST_HEAD;

typedef struct hlist_node {
	struct hlist_node *next; // 指向下一个同类型的节点的指针
	struct hlist_node **pprev; // 指向前一个指向自己的指针的指针（或者说指向前一个first或者next指针的指针）
} HLIST_NODE;

// 初始化头节点
static void INIT_HLIST_HEAD(HLIST_HEAD *head)
{
	head->first = NULL;
}

// 初始化其他节点
static void INIT_HLIST_NODE(HLIST_NODE *node)
{
	node->next = NULL;
	node->pprev = &node;
}

// 插入node节点到head的后面
static void add_after_head(HLIST_HEAD *head, HLIST_NODE *node)
{
	node->next = head->first;
	node->pprev = &head->first;
	head->first = node;
	if (node->next) { // 判断first指向的节点是否存在
		node->next->pprev = &node->next;
	}
}

// 插入node节点到base节点的前面
static void add_before_base(HLIST_NODE *node, HLIST_NODE *base)
{
	node->next = base;
	*base->pprev = node;
	node->pprev = base->pprev;
	base->pprev = &node->next;
}

// 删除节点
static void del(HLIST_NODE *node)
{
	*node->pprev = node->next;
	if (node->next) {
		node->next->pprev = node->pprev; 
	}

	INIT_HLIST_NODE(node); // 初始化删除的节点，让其不再指向之前指向的节点
}

static int hlist_is_empty(HLIST_HEAD *head)
{
	return !head->first;
}

// macro
#define offsetof(type, member) \
	((size_t)(&((type *)0)->member))

#define hlist_entry(ptr, type, member) \
	((type *)((size_t)(ptr) - offsetof(type, member)))

#define hlist_for_each(cur, head) \
	for (cur = (head)->first; cur; cur = (cur)->next) 

// for循环的中间的判断条件中，如果cur指向的是链表上的最后一个节点，为了保证能进入循环，所以用逗号表达式让&&之后的表达式的结果为真
#define hlist_for_each_safe(cur, tmp, head) \
	for (cur = (head)->first; \
			(cur) && (tmp = (cur)->next, 1); \
			cur = tmp)

#define hlist_for_each_entry(ptr, cur, head, member) \
	for (cur = (head)->first; \
		(cur) && (ptr = hlist_entry(cur, typeof(*(ptr)), member)); \
		cur = (cur)->next)

#define hlist_for_each_entry_safe(ptr, cur, tmp, head, member) \
	for (cur = (head)->first; \
		(cur) && (tmp = (cur)->next, 1) \
		&& (ptr = hlist_entry(cur, typeof(*(ptr)), member)); \
		cur = tmp)
