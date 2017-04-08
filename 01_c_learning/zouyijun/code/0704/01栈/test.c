#include <stdio.h>
#include "stack.h"

int main()
{
	STACK s;
	init_stack(&s);

#define CNT 10
	SNODE nodes[CNT] = {0};
	int index[] = {0,1,2,3,4,5,6,7,8,9};
	for (int i = 0; i < CNT; i++) {
		(nodes + i)->data = i;
		INIT_LIST_HEAD(&(nodes + i)->list);
	}

	// 入栈节点
	for (int i = 0; i < CNT; i++) {
		s.push(&s, nodes + i);
	}

	printf("栈顶节点值为：%d\n", (s.top(&s))->data);

	printf("出栈：");
	while (!(s.is_empty(&s))) { // 栈不为空
		printf("%d ", (s.pop(&s))->data); // 出栈
	}
	printf("\n");

	return 0;
}
