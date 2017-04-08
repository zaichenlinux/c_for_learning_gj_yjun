#include <stdio.h>
#include "list.h"

int main()
{
	list dlist;
	init_list(&dlist);

	// 准备10个待插入的节点
#define CNT 10
	NODE s[CNT] = {0};
	for (int i = 0; i < CNT; i++) {
		(s + i)->data = i;
		dlist.node_init(s + i);
	}

	// 插入节点
	for (int i = 0; i < CNT; i++) {
		//dlist.add(&dlist, s + i);
		dlist.add_tail(&dlist, s + i);
	}
	dlist.for_each(&dlist);

	printf("查找节点：\n");
	if (dlist.search(&dlist, 10)) {
		printf("找到了！\n");
	} else {
		printf("没找到！\n");
	}

	printf("删除节点之后：");
	dlist.del(s + 9);
	dlist.for_each(&dlist);

	printf("销毁整条链表：\n");
	dlist.destroy(&dlist);

	return 0;
}
