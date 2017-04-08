#include <stdio.h>

#include "list.h"

struct data_info {
	const char *name;
	size_t age;
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

static void *print_node(struct list_info *list, struct list_node *node, void *arg)
{
	printf("name=%s, age=%d\n", ((struct data_info*)(node->priv))->name, ((struct data_info*)(node->priv))->age);

	return NULL;
}

static void *del_node(struct list_info *list, struct list_node *node, void *arg)
{
	if (((struct data_info*)(node->priv))->age == (size_t)arg) {
		list->list_del_node(list, node);
	}

	return NULL;
}

int main()
{
	struct list_info list;
	init_list(&list);

	struct list_node *ptr = NULL;
	size_t i = 0;
	for (i = 0; i < ARRAY_SIZE(arr); ++i) {
		ptr = list.alloc_node(&list, sizeof(struct data_info));

		((struct data_info*)ptr->priv)->name = arr[i].name;
		((struct data_info*)ptr->priv)->age = arr[i].age;

		list.list_add(&list, ptr);
	}

	//遍历打印
	list.list_for_each(&list, print_node, NULL);
	printf("=========================\n");

	//删除age = 20的节点
	list.list_for_each_safe(&list, del_node, (void*)20);

	//遍历打印
	list.list_for_each(&list, print_node, NULL);

	return 0;
}