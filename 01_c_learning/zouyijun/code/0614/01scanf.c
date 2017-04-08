#include <stdio.h>

int main()
{
	printf("請輸入一個字符和一個字符：");
	int num;
	char ch;
	scanf("%c%d", &ch, &num);
	printf("您輸入的數字是：%d, 字符是：%c\n", num, ch);

	return 0;	
}
