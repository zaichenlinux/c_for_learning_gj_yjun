#include <stdio.h>

/*
	1, 函数的声明仅仅就是一个说明，可以出现多次
	2, 函数的定义出现在函数的调用的后面时，函数的声明才是必须的，声明的位置必须是在调用之前	
*/

void foo(int);
int main()
{
	void foo(int i);
	foo(1);
	return 0;
}

void foo(int i)
{
	printf("%s, 参数值是：%d\n", __func__, i);
}

/*
// 函数不能重复定义
void foo(int i)
{
	printf("%s, 参数值是：%d\n", __func__, i);
}
*/
