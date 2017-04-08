#pragma once
#include <stdio.h>
#include "list.h"

// 查找算法：顺序查找，二分查找，哈希查找
// 哈希表操作：哈希算法，插入节点，查找节点，删除节点，遍历哈希表，销毁哈希表

#define ARR_LEN 3
#define KEY_LEN 10
#define VAL_LEN 20

// 下面的类型，用来描述插入到哈希链表上的节点
typedef struct hash_node {
	char *key;
	char value[VAL_LEN];
	struct list_head list;
} HNODE;

// 下面的类型，用来描述哈希链表
typedef struct hash_list {
	//struct list_head arr[4]; // 不要直接将表头放到哈希链表中
	//struct list_head (*parr)[4]; // 可以这样定义（指向元素类型是list_head的数组的指针）

	struct list_head *parr; // 指向表头数组中的第0个元素的指针

	// 哈希算法（决定了要插入的节点，会插入到数组下标对应的链表上）
	size_t (*hash_alog)(const char *key); 

	// 插入节点
	void (*insert)(struct hash_list *, const char *, const char *);

	// 查找节点
	struct list_head *(*search)(struct hash_list *, const char *);

	// 删除节点
	void (*del)(struct hash_list *, const char *key);

	// 遍历链表
	void (*list_for)(struct hash_list *);

	// 销毁链表
	void (*destroy)(struct hash_list *);
} HLIST;

// 初始化链表
void init_hlist(HLIST *);
