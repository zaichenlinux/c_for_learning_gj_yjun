#include <stdio.h>
#include "list.h"
#include "time.h"
#include "stdlib.h"

struct node {
	int score;
	struct list_head list;
};

struct node2 {
	int age;
	char *name;
	struct list_head list;
};

int main()
{
#if 0
	struct list_head head;
	INIT_LIST_HEAD(&head);
#endif
	list_head(head);

#define CNT 10
	
	srand(time(NULL));

	struct node s[CNT] = {0};
	for (int i = 0; i < CNT; i++) {
		(s + i)->score = rand()%100;
		INIT_LIST_HEAD(&(s + i)->list);

		// 插入链表
		list_add(&(s + i)->list, &head);
	}

	struct list_head *cur = NULL;
#if 0
	list_for_each(cur, &head) {
		printf("%d ", list_entry(cur, struct node, list)->score);
	}
	printf("\n");
#endif

	struct node *ptr = NULL;
	list_for_each_entry(ptr, &head, list) {
		printf("%d ", ptr->score);
	}

	struct list_head *tmp = NULL;
#if 1
	list_for_each_safe(cur, tmp, &head) {
		if (list_entry(cur, struct node, list)->score < 60)
		{ // 通过安全遍历宏，边遍历链表，边删除符合条件的节点
			//del(cur);
			del_init(cur);
		}	
	}
#endif

#if 0
	struct node *ptmp = NULL;
	//list_for_each_entry_safe(ptr, tmp, &head, list) {
	list_for_each_entry_safe_2(ptr, ptmp, &head, list) {
		if (ptr->score < 60) {
			del_init(&ptr->list);
		}
	}
#endif

	printf("\n安全遍历之后：\n");	
	list_for_each(cur, &head) {
		printf("%d ", list_entry(cur, struct node, list)->score);
	}
	printf("\n");

	

	return 0;
}
