#pragma once

//链表结点类型
struct list_node {
	struct list_node *prev;
	struct list_node *next;
	char priv[]; //0长数组，只能作为结构体最后一个成员，不占空间，预留成员名用于快速地访问该地址所在的内容
};

//链表的主对象，有头双向循环链表
struct list_info {
	struct list_node head; //头结点
	//操作方法
	struct list_node *(*alloc_node)(struct list_info *, size_t size);
	void (*__list_add)(struct list_info *list,
		struct list_node *new_node, struct list_node *prev_node, struct list_node *next_node);
	void (*list_add)(struct list_info *list,
		struct list_node *new_node);
	void (*list_add_tail)(struct list_info *list,
		struct list_node *new_node);
	void (*list_del_node)(struct list_info *list,
		struct list_node *dst_node);
	void *(*list_for_each)(struct list_info *list,
		void *(*func)(struct list_info *list, struct list_node *, void *), void *arg);
	void *(*list_for_each_safe)(struct list_info *list,
		void *(*func)(struct list_info *list, struct list_node *, void *), void *arg);
};

int init_list(struct list_info *list);