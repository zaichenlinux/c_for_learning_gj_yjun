#include <stdio.h>
#include "slist.h"

int main()
{
	// 创建链表对象
	list slist; // 声明了一个栈内存的链表对象
	//printf("data = %d\n", slist.head.data);
	//printf("next = %p\n", slist.head.next);

	init_list(&slist); // 初始化链表对象

#define CNT 10
	// 准备要插入的节点
	//NODE s[] = {{0},{1},{2},{3},{4},{5},{6},{7},{8},{9}};
	elem_t t[] = {0,1,2,3,4,5,6,7,8,9};
	NODE s[sizeof(t)] = {0};
	for (int i = 0; i < CNT; i++) {
		(s + i)->data = *(t + i);
	}

	// 插入节点10个
	for (int i = 0; i < CNT; i++) {
		//slist.insert_head(&slist, s + i);
		slist.insert_tail(&slist, s + i);
	}
	// 遍历链表
	slist.list_for_each(&slist);

	// 删除节点
	slist.del(&slist, s + 15);
	printf("删除之后，链表：");
	slist.list_for_each(&slist);

	// 查找节点
	NODE *find = slist.search(&slist, s + 19);
	if (find) {
		printf("该节点的值是：%d\n", find->data);
	}

	// 销毁链表
	slist.destroy(&slist);
	printf("销毁之后，链表：");
	slist.list_for_each(&slist);

	return 0;
}
