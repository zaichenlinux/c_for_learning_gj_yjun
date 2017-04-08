#include <stdio.h>
#include "hlist.h"

void test()
{
	int a = 10;
	int arr[10];

	int (*parr)[10] = &arr;
	for (int i = 0; i < 10; i++) {
		*(*parr + i) = i;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	int a1[] = {1,2,3,4}; // 数组中的每个元素的类型是：int
	int a2[][4] = {{1,2,3}, {1,2,2,4}}; // 数组中的每个元素(a[0],a[1])的类型是：int [4]; a[0]这个一维数组中的每个元素的类型：int
}

int main()
{
	HASH_LIST hlist;
	init_hlist(&hlist);
	// 插入的节点
	char *info[][10] = { 
		// info数组中info[0]中的每个元素的类型是：char *[10]
		// info[0]中的每一个元素的类型是：char *
		{ // key
			"tom", "tim", "mary", "kate", "henry", 
			"jim", "henter", "jim", "jim", "tom",
		},
		{ // value
			"1234", "4444", "1004", "1234", "1334",
			"3234", "1134", "3234", "0000", "9999",
		}
	};
	int n = sizeof(info[0])/sizeof(char *);

	for (int i = 0; i < n; i++) {
		hlist.insert(&hlist, *(*(info + 0) + i), *(*(info + 1) + i));
	}
	
#if 0
	HASH_NODE node = {"john1", "4567"};
	INIT_HLIST_NODE(&node.list_node);
	size_t hash_value = hlist.hash_alog(node.key) % hlist.arr_len;
	printf("另外需要插入的节点的hash_value = %lu\n", hash_value);

	add_before_base(&node.list_node, 
			((*(hlist.parr)) + hash_value)->first->next->next);
#endif

	hlist.print(&hlist);

	printf("查找：\n");
	if (hlist.search(&hlist, "jimtim")) {
		printf("找到了! \n");
	} else {
		printf("没找到！\n");
	}

	printf("删除后：\n");
	hlist.del(&hlist, "henter");
	hlist.del(&hlist, "jim");
	hlist.print(&hlist);

	printf("销毁所有的链表：\n");
	hlist.destroy(&hlist);

	return 0;
}
