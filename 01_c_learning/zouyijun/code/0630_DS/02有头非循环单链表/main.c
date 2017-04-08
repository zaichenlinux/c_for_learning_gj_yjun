#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void print_node(NODE *node)
{
	printf("%d ", node->data);
}

int main()
{
	list *slist = malloc(sizeof(list));
	if (!slist) {
		fprintf(stderr, "申请链表对象的空间失败！\n");
		return 1;
	}
	// 链表对象的初始化
	init_list(slist);

	// 插入10个节点
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(int);
	for (int i = 0; i < n; i++) {
		//slist->add(slist, i);
		slist->add_tail(slist, i);
	}
	slist->list_for(slist, print_node);
	printf("\n");

	printf("查找节点：\n");
	NODE *find = slist->search(slist, 9);
	if (find) {
		printf("找到了值为%d的节点\n", 9);
	} else {
		printf("没找到这个以该值为值的节点\n");
	}

#if 1
	//再插入两个和之前链表上某个节点值相同的节点
	slist->add(slist, 0);
	slist->add_tail(slist, 0);
	
	slist->list_for(slist, print_node);
	printf("\n");

	printf("删除节点之后：");
	slist->del(slist, 0);
	slist->list_for(slist, print_node);
	printf("\n");

	printf("销毁链表：\n");
	destroy_list(slist);
#endif
	return 0;
}
