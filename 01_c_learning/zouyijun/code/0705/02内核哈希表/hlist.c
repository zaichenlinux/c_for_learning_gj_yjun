#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hlist.h"

static size_t hash_alog(const char *key)
{
	size_t sum = 0;
	for (; *key; sum += *key, key++) {}

	return sum;
}

static void insert_node(HASH_LIST *hlist, const char *key, const char *value)
{
	size_t hash_value = hash_alog(key) % hlist->arr_len;

	HASH_NODE *ptr = NULL;
	HLIST_NODE *cur = NULL;
	hlist_for_each_entry(ptr, cur, *(hlist->parr) + hash_value, list_node) {
		if (!strcmp(ptr->key, key)) {
			if (!strcmp(ptr->value, value)) {
			} else { // key相同，value不同时，将新的value替换之前的value
				memset(ptr->value, 0, VAL_LEN);
				strcpy(ptr->value, value);
			}
			return;
		}
	}

	// key不同，准备新节点
	HASH_NODE *node = malloc(sizeof(HASH_NODE));
	assert(node);
	strcpy(node->key, key);
	strcpy(node->value, value);
	INIT_HLIST_NODE(&node->list_node);

	// 插入
	add_after_head(*(hlist->parr) + hash_value, &node->list_node);
}

static void print_list(HASH_LIST *hlist)
{
	HASH_NODE *ptr = NULL;
	HLIST_NODE *cur = NULL;
	for (int i = 0; i < hlist->arr_len; i++) {
		printf("第%d条链表：", i + 1);
		//hlist_for_each_entry(ptr, cur, *(hlist->parr) + i, list_node) {
			//printf(" --> %s:%s ", ptr->key, ptr->value);
		hlist_for_each(cur, *(hlist->parr) + i) {
			ptr = hlist_entry(cur, HASH_NODE, list_node);
			printf(" --> %s:%s ", ptr->key, ptr->value);
		}
		printf("\n");
	}	
}

static HLIST_NODE *search_node(HASH_LIST *hlist, const char *key)
{
	size_t hash_value = hlist->hash_alog(key) % hlist->arr_len;
	HASH_NODE *ptr = NULL;
	HLIST_NODE *cur = NULL;
	hlist_for_each_entry(ptr, cur, *(hlist->parr) + hash_value, list_node) {
		if (!strcmp(key, ptr->key)) {
			return &ptr->list_node;
		}
	}

	return NULL;
}

static void del_node(HASH_LIST *hlist, const char *key)
{
	size_t hash_value = hlist->hash_alog(key) % hlist->arr_len;
	HASH_NODE *ptr = NULL;
	HLIST_NODE *cur = NULL;
	HLIST_NODE *tmp = NULL;
	//hlist_for_each_entry_safe(ptr, cur, tmp, *(hlist->parr) + hash_value, list_node) {
	hlist_for_each_safe(cur, tmp, *hlist->parr + hash_value) {
		ptr = hlist_entry(cur, HASH_NODE, list_node);
		printf("key:%s, ptr->key:%s\n", key, ptr->key);
		if (!strcmp(key, ptr->key)) {
			del(&ptr->list_node);
			free(ptr);
			return;
		}
	}
}

static void destroy_list(HASH_LIST *hlist)
{
	HLIST_NODE *cur = NULL;
	HLIST_NODE *tmp = NULL;
	HASH_NODE *ptr = NULL;
	for (int i = 0; i < hlist->arr_len; i++) {
	hlist_for_each_safe(cur, tmp, *(hlist->parr) + i) { // 删除之前插入到链表的节点
			ptr = hlist_entry(cur, HASH_NODE, list_node);
			del_node(hlist, ptr->key);
		}
	}

	free(hlist->parr);
}

void init_hlist(HASH_LIST *hlist)
{
	hlist->arr_len = 3;
	hlist->parr = malloc(sizeof(HLIST_HEAD) * hlist->arr_len);
	assert(hlist->parr);
	
	// 初始化表头节点
	for (int i = 0; i < hlist->arr_len; i++) {
		INIT_HLIST_HEAD(*(hlist->parr) + i);
	}

	hlist->hash_alog = hash_alog;
	hlist->insert = insert_node;
	hlist->print = print_list;
	hlist->search = search_node;
	hlist->del = del_node;
	hlist->destroy = destroy_list;
}
