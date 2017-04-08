#include <stdio.h>
#include "sort.h"

int main(void)
{
	elem_t s[] = {3, -2, 9, 0, 5, 4, 8, 2, 0, 1};
	size_t n = sizeof(s)/sizeof(elem_t);

	struct sort sort;
	sort_init(&sort);	

	//sort.bubble(s, n);
	//sort.select(s, n);
	//sort.insert(s, n);
	//sort.quick(s, n);
	//sort.heap(s, n);
	sort.shell(s, n);
	//sort.merge(s, n);
	printf("after sort: \n");
	int i = 0;
	for (; i < n; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");

	return 0;
}
