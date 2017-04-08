#pragma once
#include "list.h"

#define KEY_LEN 10
#define VAL_LEN 20

// 描述插入到链表的节点
typedef struct hash_node {
	char key[KEY_LEN];
	char value[VAL_LEN];
	HLIST_NODE list_node;
} HASH_NODE;

// 描述哈希链表
typedef struct hash_list {
	
	size_t arr_len; // 描述数组的大小

	// 函数指针
	size_t (*hash_alog)(const char *);
	void (*insert)(struct hash_list *, const char *key, const char *value);
	HLIST_NODE *(*search)(struct hash_list *, const char *key);
	void (*del)(struct hash_list *, const char *);
	void (*print)(struct hash_list *);
	void (*destroy)(struct hash_list *);
	
	HLIST_HEAD (*parr)[0]; // 指向表头节点的指针

} HASH_LIST;

void init_hlist(HASH_LIST *);

