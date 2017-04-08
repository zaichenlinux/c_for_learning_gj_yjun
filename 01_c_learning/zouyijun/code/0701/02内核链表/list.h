#pragma once

// 下面的类型，用来描述链表上的表头节点
struct list_head {
	struct list_head *prev;
	struct list_head *next;
};

#define list_head(head) \
	struct list_head head = {&head, &head}

// 用来初始化表头节点
static void INIT_LIST_HEAD(struct list_head *head)
{
	head->next = head; 
	head->prev = head;
}

static void __add(struct list_head *node, struct list_head *prev, struct list_head *next)
{
	prev->next = node;
	next->prev = node;
	node->prev = prev;
	node->next = next;
}

// 插入节点list到head的后面
static void list_add(struct list_head *list, struct list_head *head)
{
	__add(list, head, head->next);
}

// 插入节点list到head的前面
static void list_add_tail(struct list_head *list, struct list_head *head)
{
	__add(list, head->prev, head);
}

static void del(struct list_head *list)
{
	list->prev->next = list->next;
	list->next->prev = list->prev;
}

static void del_init(struct list_head *list)
{
	list->prev->next = list->next;
	list->next->prev = list->prev;
	INIT_LIST_HEAD(list); // 删除节点后，初始化这个节点为指向他自己
}

//macro
#define offsetof(type, member) \
	((size_t)(&((type *)0)->member))

#define container_of(ptr, type, member) \
	((type *)((size_t)(ptr) - offsetof(type, member)))

// 下面的宏，用来给上面的宏起别名，list_entry这个名字通常用在链表中，还有其他名字，比如：hlist_entry通常用在哈希表中，其他容器类型用container_of这个名字
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

//通过内核链表进行普通遍历（遍历的过程中，不能删除节点）
#define list_for_each(cur, head) \
	for (cur = (head)->next;\
		  cur != (head); \
		  cur = (cur)->next)

//下面的宏用来进行安全遍历（指的是：边遍历，可以边删除节点）
#if 0 
#define list_for_each_safe(cur, tmp, head) \
	for (tmp = (head), cur = (tmp)->next; \
		  cur != (head); \
		  tmp = cur, cur = (tmp)->next)
#endif

// 上面的安全遍历宏的另一种写法(这种写法更通用)
#if 1
#define list_for_each_safe(cur, tmp, head) \
	for (cur = (head)->next, tmp = (cur)->next; \
			cur != (head); \
			cur = tmp, tmp = (tmp)->next)
#endif

//下面的宏用内核链表外面的那个大的结构体进行遍历
//参数ptr：表示指向member成员所在的那个内核链表结构外的那个结构体的指针
#define list_for_each_entry(ptr, head, member) \
	for (ptr = list_entry((head)->next, typeof(*(ptr)), member); \
			&(ptr)->member != (head); \
			ptr = list_entry((ptr)->member.next, typeof(*(ptr)), member))

//下面的宏用内核链表外面的那个大的结构体进行安全遍历
//参数tmp：是ptr指向的那个大结构体中的小结构体（list_head类型）的下一个
#define list_for_each_entry_safe(ptr, tmp, head, member) \
	for (ptr = list_entry((head)->next, typeof(*(ptr)), member), \
			tmp = (ptr)->member.next; \
			&(ptr)->member != (head); \
			ptr = list_entry(tmp, typeof(*(ptr)), member), \
			tmp = (tmp)->next)

// 上面的宏的另一种写法
// 其中第2个参数ptmp：是ptr指向的那个大结构体的下一个大结构体的地址
#define list_for_each_entry_safe_2(ptr, ptmp, head, member) \
	for (ptr = list_entry((head)->next, typeof(*(ptr)), member), \
			ptmp = list_entry((ptr)->member.next, typeof(*(ptmp)), member); \
			&(ptr)->member != (head); \
			ptr = ptmp, ptmp = list_entry((ptr)->member.next, typeof(*(ptr)), member))
