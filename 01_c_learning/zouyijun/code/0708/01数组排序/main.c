#include <stdio.h>
#include "sort.h"

int main()
{
	elem_t s[] = {3,0,6,1,9,2,4,7,5,8};
	int n = sizeof(s)/sizeof(elem_t);
	SORT sort;
	init_sort(&sort);

	sort.bubble(s, n);
	//sort.select(s, n);
	//sort.insert(s, n);

	printf("排序后：\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", *(s+i));
	}
	printf("\n");

	return 0;
}
