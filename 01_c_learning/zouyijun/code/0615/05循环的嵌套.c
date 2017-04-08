#include <stdio.h>

/*
	打印以下图形(打印多少行，用户输入决定; 下面是用户输入5的结果)：
		
	*****
	****
	***
	**
	*
	i:j
	0:5
	1:4
	2:3
	3:2
	4:1
*/

#include <ctype.h>

void print_star()
{
	int n;
	printf("请输入一个10以内的正整数：");
	scanf("%d", &n);
	
	while (n <= 0 || n > 10) {
		printf("输入不正确，您需要输入一个10以内的正整数，请重新输入：");
		scanf("%d", &n);
	}

	for (int i = 0; i < n; i++) { // 控制打印多少行
		for (int j = 0; j < (n - i); j++) { // 控制每一行打印多少个
			printf("*"); // 控制打印的东西
		}	
		printf("\n");
	}
}

int main()
{
	print_star();
	return 0;
}
