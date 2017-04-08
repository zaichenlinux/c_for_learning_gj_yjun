#include <stdio.h>
#include "sum.h"

int main()
{
	printf("请输入整数的初始值和结束值：");
	int start, end;
	scanf("%d%d", &start, &end);

	printf("和 = %d\n", sum(start, end));

	return 0;
}
