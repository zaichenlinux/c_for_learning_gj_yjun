#pragma once
#include <stdio.h>
#include "list.h"

#define TAB_SIZE 3
#define KEY_LEN 20
#define CONT_LEN 100

//哈希表上节点的类型
struct hash_node {
	char *  key; //关键字 分组的依据
	char content[CONT_LEN]; //内容
	struct list_head list;
};

//建立（插入的方式），遍历，查找，删除，销毁
//入栈，出栈，访问栈顶元素，判栈是否为空
struct hash_list {
	struct list_head *parr;
	size_t (*hash_alg)(const char *key); //哈希算法
	void (*insert)(struct hash_list *, const char *key, char *content); //插入，建立链表
	struct hash_node *(*search)(struct hash_list *, const char *key); //查找
	void (*del)(struct hash_list *, const char *key); //删除
	void (*print_list)(struct hash_list *); //打印链表
};

//初始化
void hash_init(struct hash_list *);
//销毁
void hash_destroy(struct hash_list *);

