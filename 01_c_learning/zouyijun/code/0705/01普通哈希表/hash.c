#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "hash.h"

static size_t hash_alog(const char *key)
{
	size_t sum = 0;
	for (; *key; key++) {
		sum += *key;
	}

	return sum % ARR_LEN;
}

static void insert_node(HLIST *hlist, const char *key, const char *value)
{
	size_t hash_value = hash_alog(key);

	// 先判断链表上是否存在key相同的节点
	HNODE *ptr = NULL;
	hlist_for_each_entry(ptr, hlist->parr + hash_value, list) {
		if (!strcmp(key, ptr->key)) {
			if (!strcmp(value, ptr->value)) { // key相同，value也相同
				return;
			} else { // key相同，value不同
				strcat(ptr->value, value);
				return;
			}
		}
	}

	// key和value都不同，准备一个新节点
	HNODE *node = malloc(sizeof(HNODE));
	assert(node);
	node->key = malloc(KEY_LEN);
	//printf("size KEN_LEN = %lu\n", sizeof(KEY_LEN));
	assert(node->key);
#if 1
	strcpy(node->key, key);
	strcpy(node->value, value);
	INIT_LIST_HEAD(&node->list);

	// 插入节点到链表
	list_add(&node->list, hlist->parr + hash_value);
#endif
}

static void list_for_each(HLIST *hlist)
{
	for (int i = 0; i < ARR_LEN; i++) {
		printf("第%d条链表：", i + 1);
		HNODE *ptr = NULL;
		hlist_for_each_entry(ptr, hlist->parr + i, list) {
			printf("--> %s:%s ", ptr->key, ptr->value);
		}
		printf("\n");
	}
}

static struct list_head *search_node(HLIST *hlist, const char *key)
{
	size_t hash_value = hash_alog(key);
	HNODE *ptr = NULL;
	hlist_for_each_entry(ptr, hlist->parr + hash_value, list) {
		if (!strcmp(key, ptr->key)) {
			return &ptr->list;
		}
	}
	return NULL;
}

static void del_node(HLIST *hlist, const char *key)
{
	size_t hash_value = hash_alog(key);
	HNODE *ptr = NULL;
	hlist_for_each_entry(ptr, hlist->parr + hash_value, list) {
		if (!strcmp(key, ptr->key)) {
			list_del_init(&ptr->list);
			free(ptr->key);
			free(ptr);
			return;
		}
	}
}

static void destroy_hlist(HLIST *hlist)
{
	HNODE *ptr = NULL;
	list_head *tmp = NULL;
	for (int i = 0; i < ARR_LEN; i++) {
		// 删除每一条链表上插入的那些节点
		hlist_for_each_entry_safe(ptr, tmp, hlist->parr + i, list) {
			hlist->del(hlist, ptr->key);
		}
	}

	free(hlist->parr);
}

void init_hlist(HLIST *hlist)
{
	hlist->parr = malloc(sizeof(list_head) * ARR_LEN);
	assert(hlist->parr);

	// 初始化表头节点
	for (int i = 0; i < ARR_LEN; i++) {
		INIT_LIST_HEAD(hlist->parr + i);
	}

	hlist->hash_alog = hash_alog;
	hlist->insert = insert_node;
	hlist->list_for = list_for_each;
	hlist->search = search_node;
	hlist->del = del_node;
	hlist->destroy = destroy_hlist;
}

