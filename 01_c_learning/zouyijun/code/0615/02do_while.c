#include <stdio.h>

// 计算一个整数的位数（比如：输入123, 打印3位数）

// 用while循环实现
int bit_number()
{
	printf("请输入一个正整数：");
	int n;
	scanf("%d", &n);
	int bit = 0; // 统计位数的
	if (n == 0) {
		bit = 1;
	}

	while (n > 0) {
		bit++;
		n /= 10;
	}
	return bit;
}

/*
	// 直到型循环
	do {
		循环体内执行的代码
	} while (条件);

	while 和 do...while 的区别：
		while循环在条件不成立时，循环体一次也不执行
		do...while循环不管条件是否成立，至少会执行一次循环体
*/

// 用do...while循环实现
int bit_number_2()
{
	printf("请输入一个正整数：");
	int n;
	scanf("%d", &n);
	int bit = 0; // 统计位数的

	do {
		bit++;
		n /= 10;
	} while (n > 0);

	return bit;	
}

int main()
{
	printf("%d位数\n", bit_number_2());
	return 0;
}
