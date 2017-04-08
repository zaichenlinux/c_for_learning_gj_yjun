#include <stdio.h>
#include "sort.h"

typedef int elem_t;

typedef struct node {
	elem_t data;
	list_head list;
} NODE;

static int cmp_data(list_head *a, list_head *b)
{
	NODE *pa = container_of(a, NODE, list);
	NODE *pb = container_of(b, NODE, list);
	return pa->data - pb->data;
}

int main()
{
	elem_t s[] = {0,7,3, 2,8,4,9, -7, 1,5,6, -1};
	int n = sizeof(s)/sizeof(elem_t);
	NODE nodes[n];

	list_head(head);
	
	for (int i = 0; i < n; i++) {
		(nodes + i)->data = *(s + i);
		INIT_LIST_HEAD(&(nodes + i)->list);
		list_add_tail(&(nodes + i)->list, &head);
	}

#if 0	
	NODE *ptr = NULL;
	printf("before swap: \n");
	list_for_each_entry(ptr, &head, list) {
		printf("%d ", ptr->data);
	}
	printf("\n");
#endif

	SORT sort;
	init_sort(&sort);
	
#if 1
	//sort.swap(&(nodes + 0)->list, &(nodes + 9)->list);
	//printf("after swap: \n");
	printf("after sort: \n");
	//sort.bubble(&head, cmp_data);
	//sort.select(&head, cmp_data);
	sort.insert(&head, cmp_data);
	NODE *ptr = NULL;
	list_for_each_entry(ptr, &head, list) {
		printf("%d ", ptr->data);
	}
	printf("\n");
#endif

	return 0;
}
