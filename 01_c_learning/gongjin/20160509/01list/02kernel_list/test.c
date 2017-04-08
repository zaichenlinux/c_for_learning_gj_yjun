#include <stdio.h>

#include "m_kernel_list.h"

struct data_info {
	const char *name;
	size_t age;
	struct list_head node; //内核链表节点
};

static struct data_info arr[] = {
	{"aaaaa", 10},
	{"bbb", 20},
	{"cccc"},
	{"ddd", 38},
	{"hh", 20},
	{"qqq", 11},
	{"mm", 66},
};

#define ARRAY_SIZE(n) (sizeof(n) / sizeof(n[0]))

int main()
{
	struct list_head head;
	INIT_LIST_HEAD(&head);

	size_t i = 0;
	for (i = 0; i < ARRAY_SIZE(arr); ++i) {
		list_add_tail(&arr[i].node, &head);
	}

	struct list_head *ptr = NULL;
	struct data_info *pdata = NULL;

	//遍历打印
	list_for_each(ptr, &head) {
		pdata = container_of(ptr, struct data_info, node);
		printf("%s, %d\n", pdata->name, pdata->age);
	}
	printf("=========================\n");

	//删除age = 20的节点
	struct list_head *n = NULL; //临时变量
	list_for_each_safe(ptr, n, &head) {
		pdata = container_of(ptr, struct data_info, node);
		if (pdata->age == 20) {
			list_del_init(ptr);
		}
	}

	//遍历打印
	list_for_each(ptr, &head) {
		pdata = container_of(ptr, struct data_info, node);
		printf("%s, %d\n", pdata->name, pdata->age);
	}

	return 0;
}