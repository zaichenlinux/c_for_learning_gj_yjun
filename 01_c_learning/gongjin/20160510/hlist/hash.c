#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

static inline size_t hash_alg(const char *key)
{
	size_t sum = 0;
	while (*key) {
		sum += *key++;
	}

	return sum % TAB_SIZE;
}

static inline void insert(struct hash_list *hlist, const char *key, char *content)
{
	size_t hash_val = hlist->hash_alg(key);

	//处理链表上存在key相同的节点的情况
	struct hash_node *pnode;
	struct list_head *cur = NULL;
	hlist_for_each(cur, hlist->parr + hash_val) {
		pnode = hlist_entry(cur, struct hash_node, list);
		if (!strcmp(key, pnode->key)) {
				if (!strcmp(content, pnode->content)) {
					return;
				} else {
					strcat(pnode->content, content);
					return;
				}
		}	
	}	

	//处理链表上存在key不同的节点的情况
	struct hash_node *node = (struct hash_node *)malloc(sizeof(struct hash_node));
	assert(node);
	node->key = (char *)malloc(KEY_LEN);
	assert(node->key);
	strcpy(node->key, key);
	strcpy(node->content, content);
	INIT_LIST_HEAD(&node->list);

	//插入链表
	list_add(&node->list, hlist->parr + hash_val);
}

static inline struct hash_node *hash_search(struct hash_list *hlist, const char *key)
{
	size_t hash_val = hlist->hash_alg(key);
	
	struct hash_node *pnode = NULL;
	hlist_for_each_entry(pnode, hlist->parr + hash_val, list) {
		if (!strcmp(key, pnode->key)) {
			return pnode;
		}
	}
	return NULL;
}

static inline void hash_del(struct hash_list *hlist, const char *key)
{
	size_t hash_val = hlist->hash_alg(key);
	
	struct hash_node *pnode = NULL;
	hlist_for_each_entry(pnode, hlist->parr + hash_val, list) {
		if (!strcmp(key, pnode->key)) {
			list_del(&pnode->list);
			free(pnode->key);
			free(pnode);
			return;
		}
	}
}

static inline void print_list(struct hash_list *hlist)
{
	int i = 0;
	struct hash_node *pnode = NULL;
	for (; i < TAB_SIZE; i++) {
		printf("list%d: \n\t", i);
		hlist_for_each_entry(pnode, hlist->parr + i, list) {
			printf("%s: %s --> ", pnode->key, pnode->content);
		}
		printf("\n");
	}
}

void hash_init(struct hash_list *hlist)
{
	hlist->parr = (struct list_head *)malloc(sizeof(struct list_head) * TAB_SIZE);
	assert(hlist->parr);

	//初始化表头
	int i = 0;
	for (; i < TAB_SIZE; i++) {
		INIT_LIST_HEAD(hlist->parr + i);
	}

	hlist->hash_alg = hash_alg;
	hlist->insert = insert;
   	hlist->search = hash_search;
	hlist->del = hash_del;	
	hlist->print_list = print_list;	
}

void hash_destroy(struct hash_list *hlist) 
{
	int i = 0;
	struct hash_node *pnode = NULL;
	struct list_head *tmp = NULL;
	for (; i < TAB_SIZE; i++) {
		hlist_for_each_entry_safe(pnode, tmp, hlist->parr + i, list) {
			hlist->del(hlist, pnode->key);
		}	
	}

	free(hlist->parr);
}
