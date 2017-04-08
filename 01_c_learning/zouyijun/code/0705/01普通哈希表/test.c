#include "hash.h"

#if 0
	int months[][13] = {
		{0,31,28,31,30,31,30,31,31,30,31,30,31}, // 平年 
		{0,31,29,31,30,31,30,31,31,30,31,30,31}, // 闰年
	};
#endif

int main()
{
	// 准备要插入的节点的key和value
	const char *name[] = {
		"tom", "tim", "mary", "kate", "henry",
		"jim", "henter", "jim", "jim", "tom",			
	};
	const char *tel[] = {
		"1234", "4444", "1004", "1234", "1334",
		"3234", "1134", "3234", "0000", "9999",
	};
	int n = sizeof(name)/sizeof(char*);

	HLIST hlist;
	init_hlist(&hlist);

	// 插入节点
	for (int i = 0; i < n; i++) {
		hlist.insert(&hlist, *(name + i), *(tel + i));
	}
	
#if 1
	hlist.list_for(&hlist);

	printf("查找节点：");
	struct list_head *result = hlist.search(&hlist, "tim");
	if (result) {
		printf("这个节点在%lu条链表上，其value为：%s\n", 
				hlist.hash_alog("tim") + 1, 
				hlist_entry(result, HNODE, list)->value);	
	} else {
		printf("不存在这个节点\n");
	}

	printf("\n删除节点后：\n");
	hlist.del(&hlist, "tim");
	hlist.list_for(&hlist);
#endif

	hlist.destroy(&hlist);

	return 0;
}

#if 0
// 之前的写法
int main()
{
	HNODE nodes[] = {
		{"tom", "1234"},
		{"tim", "4444"},
		{"mary", "1004"},
		{"kate", "1234"},
		{"henry", "1334"},
		{"jim", "3234"},
		{"henter", "1134"},
		{"jim", "3234"},
		{"jim", "0000"},
		{"tom", "9999"},
	};
	int n = sizeof(nodes)/sizeof(HNODE);
	for (int i = 0; i < n; i++) {
		INIT_LIST_HEAD(&(nodes + i)->list);
	}
	
	HLIST hlist;
	init_hlist(&hlist);

	// 插入节点
	for (int i = 0; i < n; i++) {
		hlist.insert(&hlist, (nodes + i)->key, (nodes + i)->value);
	}
	hlist.list_for(&hlist);

	printf("查找节点：");
	struct list_head *result = hlist.search(&hlist, "rose");
	if (result) {
		printf("这个节点在%lu条链表上，其value为：%s\n", 
				hlist.hash_alog("tim") + 1, 
				hlist_entry(result, HNODE, list)->value);	
	} else {
		printf("不存在这个节点\n");
	}

	printf("\n删除节点后：\n");
	hlist.del(&hlist, "tim");
	hlist.list_for(&hlist);
	
	return 0;
}
#endif
